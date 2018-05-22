/*
 Project: "Stop me" LED game
 Version: 1.0
 Author: Domagoj Špoljar @ e-radionica.com
 Created: 17.09.2017
 Web: 

 Simple LED game where player must track which LED is blinking and
 press pushbutton when the green LED lights up.
 
 Features:
 -code optimised for attiny13a
 -uses less than 1KB of memory
 -12 different blinking speeds
 -powered by small CR2032 battery
 
 Arduino core for attiny85 - http://drazzy.com/package_drazzy.com_index.json 
 Arduino core for attiny13 - https://mcudude.github.io/MicroCore/package_MCUdude_MicroCore_index.json
*/

#include <avr/io.h>
#include <avr/interrupt.h>
//#include <util/delay.h>

#define F_CPU 1000000UL // 1Mhz CPU

volatile unsigned long millisec = 0;
volatile uint8_t previousReading  = 1; // holds last 8 pin reads from pushbutton
volatile uint8_t buttonWasPressed = 1; // keeps track of debounced button state, 0 false, 1 true
volatile uint8_t b_pressed = 0;
volatile uint8_t i = 0;                // counter variable

bool z = true;
unsigned long previousms = 0;
unsigned long ppreviousms = 0;
bool prijelaz = false;
int interval = 1000;
uint8_t br_blinkanja = 0;


void setLED(uint8_t LED)
{
  //Clear existing status, we can only drive one LED at a time
  PORTB &= 0xF0;    // Set the lower 3 bits to 0, i.e. off
  DDRB |= 0x07;   // Set the lower 3 bits to 1, i.e. output
  

  switch (LED)
  {
    case 1:
      DDRB  &= 0xFB;  // Disconnect the nr. 2 pin
      PORTB |= 0x01;  // Set pin 0 to high and pin 1 to low
      break;

    case 5:
      DDRB  &= 0xFB;  // Disconnect the nr. 2 pin
      PORTB |= 0x02;  // Set pin 1 to high and pin 0 to low
      break;

    case 4:
      DDRB  &= 0xFE;  // Disconnect the nr. 0 pin
      PORTB |= 0x02;  // Set pin 1 to high and pin 2 to low
      break;

    case 3:
      DDRB &= 0xF8; // Set pin 3 to output
      PORTB |= 0x08;  // Set pin 3 to high
      break;

    case 0:
      DDRB  &= 0xFE;  // Disconnect the nr. 0 pin
      PORTB |= 0x04;  // Set pin 2 to high and pin 1 to low
      break;

    case 6:
      DDRB  &= 0xFD;  // Disconnect the nr. 1 pin
      PORTB |= 0x01;  // Set pin 0 to high and pin 2 to low
      break;

    case 2:
      DDRB  &= 0xFD;  // Disconnect the nr. 1 pin
      PORTB |= 0x04;  // Set pin 2 to high and pin 0 to low
      break;

    default:
      break;
  }
}

static inline void initTimer0(void)         // timer0 is by default set to normal mode
{                                           // where it can count to 256 (FF) and then it overflows

  TCCR0B |= (_BV(CS02));                    // prescaler 256
  TIMSK0 |= (1 << OCIE0A) | (1 << OCIE0B);  // Enable CTC interrupt for OCR0A and OCR0B
  OCR0A = 3;                                // Set timer to compare 1 millisecond
  OCR0B = 122;                             // Set timer to compare 30 milliseconds
  sei();                                   // Enable global interrupts
}

ISR(TIM0_COMPA_vect) // when OCR0A gets a match (every 1ms) execute folowing...
{
  OCR0A += 2;  // used because of timer overflowing
  ++millisec; // add 1 to millisec variable which is used for measuring time
}

ISR(TIM0_COMPB_vect)
{
  OCR0B += 122;                                 //used because of timer overflowing
  if ((PINB & (1 << PB4)) != previousReading)   // if current button pin reading doesn't equal previousReading 30ms ago,
  {
    if (!buttonWasPressed)                    // and button wasn't pressed last time
    {
      if (i == 3) {                           // check which LED diode is on
        b_pressed = 1;                        // if LED 3 (green LED) is on 
      }
      else {                                  // if any other LED is on
        b_pressed = 2;
      }
      PORTB |= (1 << PB4);                    // keep pushbutton pull-up resistor on
      buttonWasPressed = 1;                   // set debounced button press state to 1
    }
    else
      buttonWasPressed = 0;                   // button has been let go, reset buttonWasPressed
  }
  previousReading = (PINB & (1 << PB4));      // set previous reading to current reading for next time
}



int main(void)
{

  DDRB = 0x0F;         // enable PB0-PB3 as an output
  PORTB |= (1 << PB4); // enable pullup on pushbutton output hooked up to PB4
  initTimer0();        // set up timer0

  while (1)            // loop
  {

    if (!prijelaz) {

      if (b_pressed != 0) {

        if (b_pressed == 1) {       // if the button is pressed when green LED is light up
                                    // make LEDs blink faster
          if (interval != 75) {
            if (interval <=125) interval = interval - 25 ;
            else if (interval <= 400) interval = interval - 50;
            else interval = interval - 125;
          }

        }
        else if (b_pressed == 2) {   //if the button is pressed when any of red LED is light up
          interval = 1000;            //reset LED blinking time to initial time
        };

        b_pressed = 0;
        prijelaz = true;
        ppreviousms = millisec;
      }

      else {

        setLED(i);

        if (millisec - previousms >= interval) {
          previousms = millisec;
          if (z) {
            i++;
            if (i == 6) {
              z = false;
            }
          }
          else {
            i--;
            if (i == 0) {
              z = true;
            }
          };
          
        };
      };
     // ppreviousms = millisec;
    }

    else {

      if (br_blinkanja < 5) {
        if (millisec - ppreviousms >= 400) {
          ppreviousms = millisec;
          if (br_blinkanja == 0 || br_blinkanja == 2 || br_blinkanja == 4) {
            PORTB &= 0xF0;    // Set the lower 3 bits to 0, i.e. off
            DDRB |= 0x07;   // Set the lower 3 bits to 1, i.e. output
            //PORTB |= (1 << PB4);
          }
          else {
            setLED(i);
          };

          br_blinkanja++;
        };

      }
      else {
        br_blinkanja = 0;
        prijelaz = false;
        b_pressed = 0;
        if (z) {
            i++;
            if (i == 6) {
              z = false;
            }
          }
          else {
            i--;
            if (i == 0) {
              z = true;
            }
          };
        
      };
      previousms = millisec;
    }
  }
}



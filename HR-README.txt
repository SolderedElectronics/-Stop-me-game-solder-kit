# DIY_Stop_Me_Game_Kit

# Opis i pojedinosti
Igra "Stop Me" je mala i jednostavna igra koja je bazirana na ATtiny13a mikrokontroleru. Sastoji se od 7 LED dioda (6 dioda iste boje i jedna razli�ite), tipkala, male CR2032 baterije i mikrokontrolera. Igra po�inje sekvencijalnim osvjetljavanjem LED dioda. LED dioda u sredini (4. u redu) je druga�ije boje u odnosu na ostatak LED dioda. Cilj igre je vrlo jednostavan, igra� mora pritisnuti gumb kada se upali srednja LED dioda (jedina razli�ite boje). Ako se pritisne tipkalo dok je ispravna LED dioda osvjetljena, igra prelazi na sljede�u razinu, pri �emu se pove�ava brzina sekvencijalnog osvjetljavanja izme�u LED dioda. Ako je bilo koja druga LED dioda osvjetljena kada pritisnete tipku, igra se ponovno pokre�e na prvu razinu. Igra je dizajnirana da ima vi�e razina (ukupno 12).


Ova igra je dizajnirana kao DIY (Do It Yourself) set  za lemljenje. Ovaj set je idealan za djecu i po�etnike lemljenja koji mogu vje�bati svoje vje�tine s ovom jednostavnom i malenom igrom. Dok u�ite lemliti, tako�er �ete stvoriti jedinstveni gadget koji mo�ete nositi uokolo. Osim toga, igranjem ove jednostavne igre, igra�i mogu vje�bati svoje refleksne vje�tine.

# Sadr�aj repozitorija

Ovaj repozitorij je podijeljen u dva dijela: Eagle Files i Firmware. Mapa Eagle Files sadr�i Cadsoft Eagle .sch i .brd datoteke za PCB plo�u "STOP ME". Osim toga nalazi se shema plo�ice u .pdf formatu. U mapi Firmware mo�ete prona�i C kod za programiranje ATtiny13 mikrokontrolera. Cijeli programski kod koristi manje od 1kB Flash memorije.

# Upute za lemljenje

1. Stavite 8-pinski holder IC-a u IC. Okrenite plo�icu, a zatim ga zalemite na mjesto.
2. Umetnite prekida� i tipkalo u S1 i S2. Okrenite plo�icu i zalemite sve na mjesto.
3. Umetnite 7 LED dioda u LED1, LED2, LED2, LED3, LED4, LED5, LED6. Svaka LED dioda ima kratku i du�u no�icu. Du�a no�ica ide u rupu koja je najbli�a znaku "+" na plo�ici. NAPOMENA: LED dioda razli�ite boje treba umetnuti u polo�aj LED4. Okrenite plo�icu, a zatim zalemite sve na mjesto.
4. Preokrenite plo�icu. Stavite dr�a� baterije CR2032 u BAT mjesto. U ovom koraku nemojte jo� stavljati bateriju u dr�a�. Ponovno okrenite plo�icu i zalemite na mjesto. Dr�a� baterije je jedina komponenta koja se nalazi na stra�njem dijelu plo�ice.
5. Umetnite Attiny13 mikrokontroler na 8-pinski IC holder. Kada se mikrokontroler umetne, to�ka koja ozna�ava polo�aj �ipa bi se trebala nalaziti dolje lijevo.
6. Umetnite bateriju CR2032 u dr�a� baterije.
7. To je to! Okrenite prekida� na ON polo�aj i igra bi trebala po�eti svijetliti. U�ivajte u igranju!

# Verzije plo�e
- v1.0 - po�etna verzija

# Podaci o licenci
Ovaj je proizvod open source. Yay!
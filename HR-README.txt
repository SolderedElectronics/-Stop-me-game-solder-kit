# DIY_Stop_Me_Game_Kit

# Opis i pojedinosti
Igra "Stop Me" je mala i jednostavna igra koja je bazirana na ATtiny13a mikrokontroleru. Sastoji se od 7 LED dioda (6 dioda iste boje i jedna razlièite), tipkala, male CR2032 baterije i mikrokontrolera. Igra poèinje sekvencijalnim osvjetljavanjem LED dioda. LED dioda u sredini (4. u redu) je drugaèije boje u odnosu na ostatak LED dioda. Cilj igre je vrlo jednostavan, igraè mora pritisnuti gumb kada se upali srednja LED dioda (jedina razlièite boje). Ako se pritisne tipkalo dok je ispravna LED dioda osvjetljena, igra prelazi na sljedeæu razinu, pri èemu se poveèava brzina sekvencijalnog osvjetljavanja izmeðu LED dioda. Ako je bilo koja druga LED dioda osvjetljena kada pritisnete tipku, igra se ponovno pokreæe na prvu razinu. Igra je dizajnirana da ima više razina (ukupno 12).


Ova igra je dizajnirana kao DIY (Do It Yourself) set  za lemljenje. Ovaj set je idealan za djecu i poèetnike lemljenja koji mogu vježbati svoje vještine s ovom jednostavnom i malenom igrom. Dok uèite lemliti, takoðer æete stvoriti jedinstveni gadget koji možete nositi uokolo. Osim toga, igranjem ove jednostavne igre, igraèi mogu vježbati svoje refleksne vještine.

# Sadržaj repozitorija

Ovaj repozitorij je podijeljen u dva dijela: Eagle Files i Firmware. Mapa Eagle Files sadrži Cadsoft Eagle .sch i .brd datoteke za PCB ploèu "STOP ME". Osim toga nalazi se shema ploèice u .pdf formatu. U mapi Firmware možete pronaæi C kod za programiranje ATtiny13 mikrokontrolera. Cijeli programski kod koristi manje od 1kB Flash memorije.

# Upute za lemljenje

1. Stavite 8-pinski holder IC-a u IC. Okrenite ploèicu, a zatim ga zalemite na mjesto.
2. Umetnite prekidaè i tipkalo u S1 i S2. Okrenite ploèicu i zalemite sve na mjesto.
3. Umetnite 7 LED dioda u LED1, LED2, LED2, LED3, LED4, LED5, LED6. Svaka LED dioda ima kratku i dužu nožicu. Duža nožica ide u rupu koja je najbliža znaku "+" na ploèici. NAPOMENA: LED dioda razlièite boje treba umetnuti u položaj LED4. Okrenite ploèicu, a zatim zalemite sve na mjesto.
4. Preokrenite ploèicu. Stavite držaè baterije CR2032 u BAT mjesto. U ovom koraku nemojte još stavljati bateriju u držaè. Ponovno okrenite ploèicu i zalemite na mjesto. Držaè baterije je jedina komponenta koja se nalazi na stražnjem dijelu ploèice.
5. Umetnite Attiny13 mikrokontroler na 8-pinski IC holder. Kada se mikrokontroler umetne, toèka koja oznaèava položaj èipa bi se trebala nalaziti dolje lijevo.
6. Umetnite bateriju CR2032 u držaè baterije.
7. To je to! Okrenite prekidaè na ON položaj i igra bi trebala poèeti svijetliti. Uživajte u igranju!

# Verzije ploèe
- v1.0 - poèetna verzija

# Podaci o licenci
Ovaj je proizvod open source. Yay!
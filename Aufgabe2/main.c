/* Der ATmega328P läuft mit einer Frequenz von 16 MHz */
#define F_CPU 16000000L

/* Einbinden der benötigten Bibliotheken */
#include <avr/io.h>
// TODO: Bibliothek einbinden
#include <util/delay.h>

int main() {

	/*	
	Alle Bits des DataDirectionRegister von Port D
	(DDRD) werden auf LOW gesetzt, sind somit als
	Eingang konfiguriert.
	In Binärschreibweise ist DDRD jetzt: 00000000 
	*/
	DDRD = 0x00;              

	/*	
	Das Bit an 8. Stelle (D7) wird auf Eins
	gesetzt -> Ausgang
	In Binärschreibweise ist DDRD jetzt: 10000000
	*/
	// TODO: setzen von Pin D7 auf HIGH (Ausgang) im Data Direction Register DDRD
	DDRD |= (1<<DDD7);

	while(1) {
		// Das Förderband dreht vorwärts
		// TODO: Pin D7 in Register PORTD auf HIGH schalten
		PORTD |= (1<<PORTD7);
		// Das Programm wird um 1000 ms verzögert
		// TODO: delay von 1000 ms einfügen
		_delay_ms(1000);
		// Das Förderband wird angehalten
		// TODO: Pin D7 in Register PORTD auf LOW schalten
		PORTD &= ~(1<<PORTD7);
		// Das Programm wird um 1000 ms verzögert
		// TODO: delay von 1000 ms einfügen
		_delay_ms(1000);
	}
}
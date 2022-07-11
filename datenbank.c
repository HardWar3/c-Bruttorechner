#include <stdio.h>
#include <stdlib.h>

int datenbank( long firma, long personalnummer );

int datenbank( long firma, long personalnummer ) {

	long datenbank_firma[4] = { 12345678, 23456789, 10382457, 234542 };
	long datenbank_personalnummer[6] = { 12345678, 1, 2, 3, 4, 5 };

	long len = sizeof( datenbank_firma ) / sizeof( datenbank_firma[0] );
	long plen = sizeof( datenbank_personalnummer ) / sizeof( datenbank_personalnummer[0] ) ;

	for ( int index = 0; index < len; index++  ) {
	
		if ( datenbank_firma[ index ] == firma && datenbank_personalnummer[0] == firma ) {
		
			for ( int dex = 1; dex < plen; dex++ ) {
			
				if ( datenbank_personalnummer[ dex ] == personalnummer ) {
				
					return(0);
				
				}
			
			}

			printf( "die Firma ist vorhanden aber der Mitarbeiter ist noch nicht angelegt worden, Personalnummer %ld \n", personalnummer );
			return(1);
		
		}
	
	}

	printf( "die Firma ist in der Dankenbank nicht angelegt Firmennummer %ld - Programm wurde beendet - \n", firma );
	return 1;

}

#include <stdio.h>
#include <stdlib.h>

#include "user_daten.h"

extern double tab( int tab, int index_tab );

extern double aufrunden_double( double was );

void mre4alte( struct user_daten *user );

void mre4alte ( struct user_daten *user ) {

	if ( user -> alter1 == 0 ) {
	
		user -> alte = 0;

	} else {
	
		if ( user -> ajahr < 2006 ) {
		
			user -> k = 1;
		
		} else if ( user -> ajahr < 2040 ) {
		
			user -> k = user -> ajahr - 2004;
		
		} else {
		
			user -> k = 36;
		
		}

		user -> bmg = user -> zre4j - user -> zvbezj;

		user -> alte = aufrunden_double( user -> bmg * tab( 4, user -> k ) ); // aufrunden auf euro

		user -> hbalte = (int) tab( 5, user -> k );

		if ( user -> alte > user -> hbalte ) {
		
			user -> alte = user -> hbalte;

		}
	
	}

}

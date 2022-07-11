#include <stdio.h>
#include <stdlib.h>

#include "user_daten.h"

extern void mst5_6( struct user_daten *user );
extern void uptab19( struct user_daten *user );

extern double abrunden_double( int wo, double was );

void upmlst( struct user_daten *user );

void upmlst( struct user_daten *user ){

	if ( user -> zve < 1 ) {
	
		user -> zve = 0;

		user -> x = 0;

	} else {

		user -> x = abrunden_double( 0, ( user -> zve / user -> kztab ) ); // abrunden auf gane euro

	}

	if ( user -> stkl < 5 ) {
	
		uptab19( user );
	
	} else {
	
		mst5_6( user );
	
	}

}

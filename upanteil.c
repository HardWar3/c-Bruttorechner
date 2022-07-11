#include <stdio.h>
#include <stdlib.h>

#include "user_daten.h"

extern double abrunden_double( int wo, double was);

void upanteil( struct user_daten *user );

void upanteil( struct user_daten *user ) {

	if ( user -> lzz == 1 ) {
	
		user -> anteil1 = user -> jw;

	} else if ( user -> lzz == 2 ) {
	
		user -> anteil1 = abrunden_double( 2, ( user -> jw / 12.0 ) ); // abrunden

	} else if ( user -> lzz == 3 ) {
	
		user -> anteil1 = abrunden_double( 2, ( user -> jw * 7 / 360.0 ) ); // abrunden

	} else {
	
		user -> anteil1 = abrunden_double( 2, ( user -> jw / 360.0 ) ); // abrunden

	}

}

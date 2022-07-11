#include <stdio.h>
#include <stdlib.h>

#include "user_daten.h"

extern double abrunden_double( int wo, double was );

void uptab19( struct user_daten *user );

void uptab19( struct user_daten *user ) {

	if ( user -> x < user -> gfb + 1 ) {
	
		user -> st = 0;
	
	} else if ( user -> x < 14255 ) {
	
		user -> y = ( user -> x - user -> gfb ) * 0.0001;

		user -> rw = user -> y * ( (double) 980.14 );

		user -> rw = user -> rw + 1400;

		user -> st = abrunden_double( 0, ( user -> rw * user -> y ) ); // abrunden auf ganze euro

	} else if ( user -> x < 55961 ) {
	
		user -> y = ( user -> x - 14254 ) * 0.0001;

		user -> rw = user -> y * ( (double) 216.16 );

		user -> rw = user -> rw + 2397;

		user -> rw = user -> rw * user -> y;

		user -> st = abrunden_double( 0, ( user -> rw + ( (double) 965.58 ) ) ); // abrunden auf ganze euro
	
	} else if ( user -> x < 265327 ) {
	
		user -> st = abrunden_double( 0, ( user -> x * ( (double) 0.42 ) - ( (double) 8780.9 ) ) ); // abrunden auf ganze euro
	
	} else {
	
		user -> st = abrunden_double( 0, ( user -> x * ( (double) 0.45 ) - ( (double) 16740.68 ) ) ); // abrunden auf ganze euro

	}

	user -> st = user -> st * user -> kztab;

}

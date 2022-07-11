#include <stdio.h>
#include <stdlib.h>

#include "user_daten.h"

extern void uptab19( struct user_daten *user );

extern double abrunden_double( int wo, double was );

void up5_6( struct user_daten *user );

void up5_6( struct user_daten *user ) {

	 user -> x = user -> zx * ( (double) 1.25 );

	 uptab19( user );

	 user -> st1 = user -> st;

	 user -> x = user -> zx * ( (double) 0.75 );

	 uptab19( user );

	 user -> st2 = user -> st;

	 user -> diff = ( user -> st1 - user -> st2 ) * 2;

	 user -> mist = abrunden_double( 0, ( user -> zx * ( (double) 0.14 ) ) ); // abrunden auf ganze euro

	 if ( user -> mist > user -> diff ) {
	 
		user -> st = user -> mist;
	 
	 } else {
	 
	 	user -> st = user -> diff;
	 
	 }

}

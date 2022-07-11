#include <stdio.h>
#include <stdlib.h>

#include "user_daten.h"

extern void upanteil( struct user_daten *user );

extern double abrunden_double( int wo, double was );

void msolz( struct user_daten *user );

void msolz( struct user_daten *user ) {

	user -> solzfrei = user -> solzfrei * user -> kztab;

	if ( user -> jbmg > user -> solzfrei ) {
	
		user -> solzj = abrunden_double( 2, ( user -> jbmg * 5.5 * 0.01 ) ); // abrunden auf cent

		user -> solzmin = ( user -> jbmg - user -> solzfrei ) * 0.20;

		if ( user -> solzmin < user -> solzj ) {
		
			user -> solzj = user -> solzmin;
		
		}

		user -> jw = user -> solzj * 100;

		upanteil( user );

		user -> solzlzz = user -> anteil1;
	
	} else {
	
		user -> solzlzz = 0;
	
	}

	if ( user -> r > 0 ) {
	
		user -> jw = user -> jbmg * 100;

		upanteil( user );

		user -> bk = user -> anteil1;

	} else {
	
		user -> bk = 0;
	
	}

}


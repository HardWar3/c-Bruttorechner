#include <stdio.h>
#include <stdlib.h>

#include "user_daten.h"

extern void mvsp( struct user_daten *user );

extern double aufrunden_double( int wo, double was );

void upevp( struct user_daten *user );

void upevp ( struct user_daten *user ) {

	if ( user -> krv > 1 ) {
	
		user -> vsp1 = 0;
	
	} else {
	
		if ( user -> zre4vp > user -> bbgrv ) {
		
			user -> zre4vp = user -> bbgrv;
		
		}

		user -> vsp1 = user -> tbsvorv * user -> zre4vp;

		user -> vsp1 = user -> vsp1 * user -> rvsatzan;
	
	}

	user -> vsp2 = ( (double) 0.12 ) * user -> zre4vp;

	if ( user -> stkl == 3 ) {
	
		user -> vhb = 3000;
	
	} else {
	
		user -> vhb = 1900;
	
	}

	if ( user -> vsp2 > user -> vhb ) {
	
		user -> vsp2 = user -> vhb;
	
	}

	user -> vspn = aufrunden_double( 0, ( user -> vsp1 + user -> vsp2 ) ); // aufrunden auf ganzen euro

	mvsp( user );

	if ( user -> vspn > user -> vsp ) {
	
		user -> vsp = user -> vspn;
	
	}

}

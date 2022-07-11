#include <stdio.h>
#include <stdlib.h>

#include "user_daten.h"

void mpara( struct user_daten *user );

void mpara( struct user_daten *user ) {
	
	if ( user->krv < 2 ) {
	
		if ( user->krv == 0 ) {
		
			user -> bbgrv = 80400;	
		
		} else {
		
			user -> bbgrv = 73800;
		
		}

		user -> rvsatzan = ( (double) 0.0930 );

		user -> tbsvorv = ( (double) 0.76 );

	}
	
	user -> bbgkvpv = 54450;

	user -> kvsatzan = user -> kvz / 200.0 + ( (double) 0.07 );

	user -> kvsatzag = ( (double) 0.0045 ) + ( (double) 0.07 );

	if ( user -> pvs == 1 ) {
	
		user -> pvsatzan = ( (double) 0.02025 );

		user -> pvsatzag = ( (double) 0.01025 );

	} else {
	
		user -> pvsatzan = ( (double) 0.01525 );

		user -> pvsatzag = ( (double) 0.01525 );

	}

	if ( user -> pvz == 1 ) {
	
		user -> pvsatzan = user -> pvsatzan + ( (double) 0.0025 );

	}

	user -> w1stkl5 = 10635;

	user -> w2stkl5 = 27980;

	user -> w3stkl5 = 212261;

	user -> gfb = 9168;

	user -> solzfrei = 972;

}

#include <stdio.h>
#include <stdlib.h>

#include "user_daten.h"

void mre4jl ( struct user_daten *user ); 

void mre4jl ( struct user_daten *user ) {

	if ( user -> lzz == 1 ) {

		user -> zre4j = user -> re4 * 0.01;

		user -> zvbezj = user -> vbez * 0.01;

		user -> jlfreib = user -> lzzfreib * 0.01;

		user -> jlhinzu = user -> lzzhinzu * 0.01;
	
	} else if ( user -> lzz == 2 ) {
	
		user -> zre4j = ( user -> re4 * 12 ) * 0.01;

		user -> zvbezj = ( user -> vbez * 12 ) * 0.01;

		user -> jlfreib = ( user -> lzzfreib * 12 ) * 0.01;

		user -> jlhinzu = ( user -> lzzhinzu * 12 ) * 0.01;

	} else if ( user -> lzz == 3 ) {
	
		user -> zre4j = ( user -> re4 * 360 / 7.0 ) * 0.01;

		user -> zvbezj = ( user -> vbez * 360 / 7.0 ) * 0.01;

		user -> jlfreib = ( user -> lzzfreib * 360 / 7.0 ) * 0.01;

		user -> jlhinzu = ( user -> lzzhinzu * 360 / 7.0 ) * 0.01; 

	} else if ( user -> lzz == 4 ) {
	
		user -> zre4j = ( user -> re4 * 360 ) * 0.01;

		user -> zvbezj = ( user -> vbez * 360 ) * 0.01;

		user -> jlfreib = ( user -> lzzfreib * 360 ) * 0.01;

		user -> jlhinzu = ( user -> lzzhinzu * 360 ) * 0.01;	
	
	}

	if ( user -> af == 0 ) {
	
		user -> f = 1;

	}

}

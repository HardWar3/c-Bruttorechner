#include <stdio.h>
#include <stdlib.h>

#include "user_daten.h"

extern void mre4( struct user_daten *user );
extern void mre4abz( struct user_daten *user );
extern void mztabfb( struct user_daten *user );
extern void mlstjahr( struct user_daten *user );

extern double double_runden( int wo, double was, int up1down0 );

void mosonst( struct user_daten *user );

void mosonst( struct user_daten *user ) {

	user -> zre4j = user -> jre4 * 0.01;

	user -> zvbezj = user -> jvbez * 0.01;

	user -> jlfreib = user -> jfreib * 0.01;

	user -> jlhinzu = user -> jhinzu * 0.01;

	mre4( user );

	mre4abz( user );

	user -> zre4vp = user -> zre4vp - user -> jre4ent * 0.01;

	mztabfb( user );

	user -> vfrbs1 = ( user -> anp + user -> fvb + user -> fvbz ) * 100;

	mlstjahr( user );

	user -> wvfrbo = ( user -> zve - user -> gfb ) * 100;

	if ( user -> wvfrbo < 0 ) {
	
		user -> wvfrbo = 0;

	}

	user -> lstoso = user -> st * 100;

}

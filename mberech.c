#include <stdio.h>
#include <stdlib.h>

#include "user_daten.h"

extern void mztabfb( struct user_daten *user );
extern void mlstjahr( struct user_daten *user );
extern void uplstlzz( struct user_daten *user );
extern void upvkvlzz( struct user_daten *user );
extern void mre4abz( struct user_daten *user );
extern void msolz( struct user_daten *user );

void mberech( struct user_daten *user );

void mberech( struct user_daten *user ) {

	mztabfb( user );

	user -> vfrb = ( user -> anp + user -> fvb + user -> fvbz ) * 100;

	mlstjahr( user );

	user -> wvfrb = ( user -> zve - user -> gfb ) * 100;

	if ( user -> wvfrb < 0 ) {
	
		user -> wvfrb = 0;
	}

	user -> lstjahr = user -> st * user -> f;

	uplstlzz( user );

	upvkvlzz( user );

	if ( user -> zkf > 0 ) {
	
		user -> ztabfb = user -> ztabfb + user -> kfb;

		mre4abz( user );

		mlstjahr( user );

		user -> jbmg = user -> st * user -> f;
	
	} else {
	
		user -> jbmg = user -> lstjahr;
	
	}

	msolz( user );

}

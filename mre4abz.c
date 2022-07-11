#include <stdio.h>
#include <stdlib.h>

#include "user_daten.h"

extern double double_runden( int wo, double was, int up1down0 );

void mre4abz( struct user_daten *user );

void mre4abz( struct user_daten *user ) {

	user -> zre4 = user -> zre4j - user -> fvb - user -> alte - user -> jlfreib + user -> jlhinzu;

	if ( user -> zre4 < 0 ) {
	
		user -> zre4 = 0;

	}

	user -> zre4vp = user -> zre4j;

	if ( user -> kennvmt == 2 ) { 
	
		user -> zre4vp = user -> zre4vp - user -> entsch * 0.01;	

	}

	user -> zvbez = user -> zvbezj - user -> fvb;

	if ( user -> zvbez < 0 ) {
	
		user -> zvbez = 0;

	}

}

#include <stdio.h>
#include <stdlib.h>

#include "user_daten.h"

extern void mre4( struct user_daten *user );
extern void mre4abz( struct user_daten *user );
extern void mztabfb( struct user_daten *user );

extern double double_runden( int wo, double was, int up1down0 );

void mre4sonst( struct user_daten *user );

void mre4sonst( struct user_daten *user ) {

	mre4( user );

	user -> fvb = user -> fvbso;

	mre4abz( user );

	user -> zre4vp = user -> zre4vp - user ->jre4ent * 0.01 - user -> sonstent * 0.01;

	user -> fvbz = user -> fvbzso;

	mztabfb( user );

	user -> vfrbs2 = ( user -> anp + user -> fvb + user -> fvbz ) * 100 - user -> vfrbs1;

}

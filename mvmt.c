#include <stdio.h>
#include <stdlib.h>

#include "user_daten.h"

extern void mosonst( struct user_daten *user );
extern void mre4sonst( struct user_daten *user );
extern void mlstjahr( struct user_daten *user );
extern void mre4abz( struct user_daten *user );

extern double abrunden_double( int wo, double was );

void mvmt( struct user_daten *user );

void mvmt( struct user_daten *user ) {

	if ( user -> vkapa < 0 ) {
	
		user -> vkapa = 0;
	
	}

	if ( user -> vmt + user -> vkapa > 0 ) {
	
		if ( user -> lstso == 0 ) {
		
			mosonst( user );

			user -> lst1 = user -> lstoso;
		
		} else {
		
			user -> lst1 = user -> lstso;
		
		}

		user -> vbezbso = user -> sterbe + user -> vkapa;

		user -> zre4j = ( user -> jre4 + user -> sonstb + user -> vmt + user -> vkapa ) * 0.01;

		user -> zvbezj = ( user -> jvbez + user -> vbs + user -> vkapa ) * 0.01;

		user -> kennvmt = 2;

		mre4sonst( user );

		mlstjahr( user );

		user -> lst3 = user -> st * 100;

		mre4abz( user );

		user -> zre4vp = user -> zre4vp - user -> jre4ent * 0.01 - user -> sonstent * 0.01;

		user -> kennvmt = 1;

		mlstjahr( user );

		user -> lst2 = user -> st * 100;

		user -> stv = user -> lst2 - user -> lst1;

		user -> lst3 = user -> lst3 - user -> lst1;

		if ( user -> lst3 < user -> stv ) {
		
			user -> stv = user -> lst3;
		
		}

		if ( user -> stv < 0 ) {
		
			user -> stv = 0;
		
		} else {
		
			user -> stv = abrunden_double( 0, ( user -> stv * user -> f ) ); // abrunden auf ganze euro
		
		}

		user -> solzv = user -> stv * ( 5.5 ) * 0.01;

		if ( user -> r > 0 ) {
		
			user -> bkv = user -> stv;
		
		} else {
		
			user -> bkv = 0;
		
		}
	
	} else {
	
		user -> stv = 0;

		user -> solzv = 0;

		user -> bkv = 0;
	
	}

}


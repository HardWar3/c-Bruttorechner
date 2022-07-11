#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "user_daten.h"

extern char *eingabe( void );
extern bool kontrolle_der_eingabe( char eingabe[] );

extern struct user_daten* user_daten_new( void );

extern void mpara( struct user_daten *user );
extern void mre4jl( struct user_daten *user );
extern void mre4( struct user_daten *user );
extern void mre4abz( struct user_daten *user );
extern void mberech( struct user_daten *user );
extern void msonst( struct user_daten *user );
extern void mvmt( struct user_daten *user );

extern double tab( int tab, int index_tab );
extern double abrunden_double( int wo, double was );

void lr_19_MW( struct user_daten *user );
	// lr - LohnRechner

void lr_19_MW( struct user_daten *user ) {
	
	mpara( user );
	mre4jl( user );

	user -> vbezbso = 0;

	user -> vbezbso = abrunden_double( 2, user -> vbezbso );

	user -> kennvmt = 0;

	mre4( user );

	mre4abz( user );

	mberech( user );

	msonst( user );

	mvmt( user );

}

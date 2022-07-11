#include <stdio.h>
#include <stdlib.h>

#include "user_daten.h"

void sv_pv_19( struct user_daten *user );

void sv_pv_19( struct user_daten *user ) {

	const double pv = 1.525;	// in % Pflegeversicherung
	const double pvs = 2.025;	// in % Sachen Pflegeversicherung
	const double pvz = 0.25;	// in % wenn ohne Kinder und älter 23

	double pv_zusammen;
	double pv_ag;

	if ( user -> pvs == 1 ) {
	
		if ( user -> pvz == 0 ) {
		
			pv_zusammen = pvs;
			pv_ag = pv;
		
		} else {
		
			pv_zusammen = pvs + pvz;
			pv_ag = pvs;
		
		}
	
	} else {
	
		if ( user -> pvz == 0 ) {
		
			pv_zusammen = pv;
			pv_ag = pv;
		
		} else {
		
			pv_zusammen = pv + pvz;
			pv_ag = pv;
		
		}
	
	}

	user -> pv_an = ( user -> re4 * ( pv_zusammen / 100.0 ) );
	user -> pv_ag = ( user -> re4 * ( pv_ag / 100.0 ) );

}

#include <stdio.h>
#include <stdlib.h>

#include "user_daten.h"

extern double aufrunden_double( int wo, double was );

void mztabfb( struct user_daten *user );

void mztabfb( struct user_daten *user ) {

	user -> anp = 0;

	if ( user -> zvbez >= 0 ) {
	
		if ( user -> zvbez < user -> fvbz ) {
		
			user -> fvbz = user -> zvbez;
		
		}
	
	}

	if ( user -> stkl < 6 ) {
	
		if ( user -> zvbez > 0 ) {
		
			if ( user -> zvbez - user -> fvbz < 102 ) {
			
				user -> anp = aufrunden_double( 0, ( user -> zvbez - user -> fvbz ) ); // aufrunden auf ganze euro
		
			} else {
			
				user -> anp = 102;
			
			}
		
		}
	
	} else {
	
		user -> fvbz = 0;

		user -> fvbzso = 0;
	
	}

	if ( user -> stkl < 6 ) {
	
		if ( user -> zre4 > user -> zvbez ) {
		
			if ( user -> zre4 - user -> zvbez < 1000 ) {
			
				user -> anp = aufrunden_double( 0, ( user -> anp + user -> zre4 - user -> zvbez ) ); // aufrunden auf gane euro

			} else {
			
				user -> anp = user -> anp + 1000;
			
			}
		
		}
	
	}

	user -> kztab = 1;

	if ( user -> stkl == 1 ) {
	
		user -> sap = 36;

		user -> kfb = user -> zkf * 7620;
	
	} else if ( user -> stkl == 2 ) {
	
		user -> efa = 1908;

		user -> sap = 36;

		user -> kfb = user -> zkf * 7620;
	
	} else if ( user -> stkl == 3 ) {

		user -> kztab = 2;

		user -> sap = 36;

		user -> kfb = user -> zkf * 7620;
	
	} else if ( user -> stkl == 4 ) {
	
		user -> sap = 36;

		user -> kfb = user -> zkf * 3810;
	
	} else if ( user -> stkl == 5 ) {
	
		user -> sap = 36;

		user -> kfb = 0;
	
	} else {
	
		user -> kfb = 0;
	
	}

	user -> ztabfb = user -> efa + user -> anp + user -> sap + user -> fvbz;

}

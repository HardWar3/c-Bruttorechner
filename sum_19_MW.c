#include <stdio.h>
#include <stdlib.h>

#include "user_daten.h"

extern double abrunden_double( int wo, double was );

void sum_19_MW( struct user_daten *user );

void sum_19_MW( struct user_daten *user ) {

	user -> lstlzz = abrunden_double( 0, user -> lstlzz );
	user -> solzlzz = abrunden_double( 0, user -> solzlzz );
	user -> kst = abrunden_double( 0, user -> kst );
	user -> gesamt_st = abrunden_double( 0, user -> gesamt_st );
	user -> netto_lohn = abrunden_double( 0, user -> netto_lohn );

	user -> gesamt_st = user -> lstlzz + user -> solzlzz + user -> kst;
	user -> sum_sozialv_an = user -> rv + user -> av + user -> kv + user -> pv_an;
	user -> sum_sozialv_ag = user -> rv + user -> av + user -> kv + user -> pv_ag;
	user -> netto_lohn = user -> re4 - ( user -> gesamt_st + user -> sum_sozialv_an );
	user -> gesamt_belast_ag = user -> re4 + user -> sum_sozialv_ag;

}

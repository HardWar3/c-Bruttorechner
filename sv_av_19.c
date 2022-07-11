#include <stdio.h>
#include <stdlib.h>

#include "user_daten.h"

void sv_av_19( struct user_daten *user );

void sv_av_19( struct user_daten *user ) {

	const double av = 0.0125;		// in % Arbeitslosenversicherung

	user -> av = user -> re4 * av;	

}

#include <stdio.h>
#include <stdlib.h>

#include "user_daten.h"

void sv_rv_19( struct user_daten *user );

void sv_rv_19( struct user_daten *user ) {

	const double rv = 0.093;	// in % Rentenversicherung

	user -> rv = user -> re4 * rv;

}

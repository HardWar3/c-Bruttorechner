#include <stdio.h>
#include <stdlib.h>

#include "user_daten.h"

void sv_kv_19( struct user_daten *user );

void sv_kv_19( struct user_daten *user ) {

	const double kv = 0.0775;		// in % Krankenversicherung

	user -> kv = user -> re4 * kv;

}

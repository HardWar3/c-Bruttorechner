#include <stdio.h>
#include <stdlib.h>

#include "user_daten.h"

extern void sv_pv_19( struct user_daten *user );
extern void sv_kv_19( struct user_daten *user );
extern void sv_av_19( struct user_daten *user );
extern void sv_rv_19( struct user_daten *user );

void sv_19_MW( struct user_daten *user );

void sv_19_MW( struct user_daten *user ){

	sv_pv_19( user );
	sv_kv_19( user );
	sv_av_19( user );
	sv_rv_19( user );

}

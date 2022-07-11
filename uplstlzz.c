#include <stdio.h>
#include <stdlib.h>

#include "user_daten.h"

extern void upanteil( struct user_daten *user );

void uplstlzz( struct user_daten *user );

void uplstlzz( struct user_daten *user ) {

	user -> jw = user -> lstjahr * 100;

	upanteil( user );

	user -> lstlzz = user -> anteil1;

}

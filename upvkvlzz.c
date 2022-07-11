#include <stdio.h>
#include <stdlib.h>

#include "user_daten.h"

extern void upvkv( struct user_daten *user );
extern void upanteil( struct user_daten *user );

void upvkvlzz( struct user_daten *user );

void upvkvlzz ( struct user_daten *user ) {

	upvkv( user );

	user -> jw = user -> vkv;

	upanteil( user );

	user -> vkvlzz = user -> anteil1;

}

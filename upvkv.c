#include <stdio.h>
#include <stdlib.h>

#include "user_daten.h"

void upvkv( struct user_daten *user );

void upvkv( struct user_daten *user ) {

	if ( user -> pkv > 0 ) {
	
		if ( user -> vsp2 > user -> vsp3 ) {
		
			user -> vkv = user -> vsp2 * 100;

		} else {
		
			user -> vkv = user -> vsp3 * 100;

		}
	
	} else {
	
		user -> vkv = 0;
	
	}

}

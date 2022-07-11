#include <stdio.h>
#include <stdlib.h>

#define eingabeRange 21

char *eingabe ( void );

char *eingabe ( void ) {

	char *eingabe = malloc( eingabeRange );

	fgets( eingabe, eingabeRange, stdin );

	return eingabe;

}

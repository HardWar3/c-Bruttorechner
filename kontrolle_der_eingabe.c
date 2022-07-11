#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool kontrolle_der_eingabe ( char eingabe[] );

bool kontrolle_der_eingabe ( char eingabe[] ) {

	char *_eingabe = strdup( eingabe );

	int laenge_der_eingabe = ( strlen( _eingabe ) -1 );

	bool only_once_komma = false;
	
	for ( int index = 0; index < laenge_der_eingabe; index++ ) {
		
		char eingabeChar;

		eingabeChar = _eingabe[ index ];

		if ( eingabeChar == ',' || eingabeChar == '.' ) {
		
			if ( only_once_komma == false ) {

				if ( eingabeChar == ',' ) {

					eingabe[ index ] = '.';

					only_once_komma = true;

				} else {

					only_once_komma = true;
				}

			} else {

				free( _eingabe );

				return true;

			}
			
		} else if ( eingabeChar < '0' || eingabeChar > '9' ) {
				
			free( _eingabe );
					
			return true;
					
		}

	}

	free( _eingabe );

	return false;

}

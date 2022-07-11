#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "user_daten.h"

extern int datenbank( long firma, long personalnummer );

int lr_parameter_pruefung( struct user_daten *user[], int user_length, double inhalt_vom_file[] );

int lr_parameter_pruefung( struct user_daten *user[], int user_length, double inhalt_vom_file[] ){

	for (int index = 0; index < user_length; index++  ) {
	
		user[index] = user_daten_new();

		int file_index;
		
		file_index = index * 13;

		printf( "index - %d\n", index );
		printf( "index - %d\n", file_index );

		user[ index ] -> id_nummer = inhalt_vom_file[ file_index ];

		printf( "XXXxxxXXX ---- %f ---- \n", user[ index ] -> id_nummer  );
		
		// id checken hier
		char id_nummer[13];
		char firmen_nummer_cp[9];
		char firmenpersonal_nummer_cp[5];

		sprintf( id_nummer, "%f", user[ index ] -> id_nummer );

		memcpy( firmen_nummer_cp, &id_nummer[0], 8 );
		memcpy( firmenpersonal_nummer_cp, &id_nummer[8], 4 );
	
	 	long firmen_nummer = atol( firmen_nummer_cp );
	 	long firmenpersonal_nummer = atol( firmenpersonal_nummer_cp );

		printf( "%ld -| STING |- \n", firmen_nummer );
		printf( "%ld -| STING |- \n", firmenpersonal_nummer );

		// das ist keine datenbank dies soll eine Art DB sein 
		// es dient nur symbolisch "datenbank" 	
		int datenbank_check = datenbank( firmen_nummer, firmenpersonal_nummer );

		if ( datenbank_check == 1 ) {
		
			return(1);
		
		}

		user[ index ] -> ajahr = inhalt_vom_file[ file_index + 1 ];

		// das alter checken
		if ( 2019 - user[ index ] -> ajahr > 64 ) {
		
			user[ index ] -> alter1 = 1;
		
		} else {
		
			user[ index ] -> alter1 = 0;
		
		}

		user[ index ] -> lzz = inhalt_vom_file[ file_index + 2 ];

		// wie soll abgerechnet werden LZZ

		if ( user[ index ] -> lzz == 1 ) {
		
			// JAHR
			user[ index ] -> re4 = inhalt_vom_file[ file_index + 3 ] * 100;
			user[ index ] -> jre4 = user[ index ] -> re4;
		
		} else if ( user[ index ] -> lzz == 2 ) {
		
			// MONAT
			user[ index ] -> re4 = inhalt_vom_file[ file_index + 3 ] * 100;
			user[ index ] -> jre4 = user[ index ] -> re4 * 12;
		
		} else if ( user[ index ] -> lzz == 3 ) {
		
			// wochen
			user[ index ] -> re4 = inhalt_vom_file[ file_index + 3 ] * 100;
			user[ index ] -> jre4 = user[ index ] -> re4 * 360 / 7.0;
		
		} else if ( user[ index ] -> lzz == 4 ) {
		
			// tag
			user[ index ] -> re4 = inhalt_vom_file[ file_index + 3 ] * 100;
			user[ index ] -> jre4 = user[ index ] -> re4 * 360;
		
		} else {
		
			// abruch des Progrsmms an dieser Stelle wegen falscher LZZ
			printf( "ERROR %f : - Feld LZZ hat ein Problem\n", user[ index ] -> id_nummer );
			return(1);
		
		}

		user[ index ] -> vbez = inhalt_vom_file[ file_index + 4 ] * 100;

		if ( user[ index ] -> re4 < 0 || user[ index ] -> vbez < 0 ) {
		
			printf( "ERROR %f : - Feld RE4 oder VBEZ sind im Negativen Wertebereich\n", user[ index ] -> id_nummer );
			return(1);
		
		}

		// vbez darf nicht größer re4 sein
		if ( user[ index ] -> vbez >= user[ index ] -> re4 ) {
		
			// return fehlercode xy
			printf( "ERROR %f : - der VBEZ ist größer RE4 - VBEZ muss kleiner RE4 sein\n", user[ index ] -> id_nummer );
			return(1);
		
		}  

		user[ index ] -> stkl = inhalt_vom_file[ file_index + 5 ];
		user[ index ] -> zkf = inhalt_vom_file[ file_index + 6 ];
		
		// steuerklasse darf nicht größer 6 oder kleiner 1 gehen und in stkl 2 muss zkf angegeben werden
		// und Kinderfreibeträge checken stkl 1 und stkl 2 wichtig
		if ( user[ index ] -> stkl < 1 || user[ index ] -> stkl > 6 ) {
		
			// return fehler code xy
			printf( "ERROR %f : - es Stimmt etwas nicht mit dem FELD STKL\n", user[ index ] -> id_nummer );
			return(1);
		
		} else if ( user[ index ] -> stkl == 2 && user[ index ] -> zkf < 0.5 ) {
		
			// return fehler code xy
			printf( "ERROR %f : - STKL 2 müssen Kinder angegeben werden\n", user[ index ] -> id_nummer );
			return(1);
		
		} else if ( user[ index ] -> stkl == 1 && user[ index ] -> zkf > 0 ) {
		
			// return fehler code xy
			printf( "ERROR %f : - STKL 1 kann keine Kinder haben\n", user[ index ] -> id_nummer );
			return(1);
		
		}

		// pvz abchecken
		if ( user[ index ] -> zkf < 0.5 && 2019 - user[ index ] -> ajahr > 23 ) {
		
			user[ index ] -> pvz = 1;
		
		}

		user[ index ] -> r = inhalt_vom_file[ file_index + 7 ];

		// religion
		if ( user[ index ] -> r < 0 || user[ index ] -> r > 1 ) {
		
			// return fehler code xy
			printf( "ERROR %f : - Religion kann nur 0 oder 1 sein\n", user[ index ] -> id_nummer );
			return(1);
		
		}

		user[ index ] -> krv = inhalt_vom_file[ file_index + 8 ];
		user[ index ] -> pvs = inhalt_vom_file[ file_index + 9 ];

		// rentenversicherung und pvs
		if ( user[ index ] -> krv < 0 || user[ index ] -> krv > 2 ) {
		
			// return fehler code xy
			printf( "ERROR %f : - Rentenversicherung kann nur 0, 1 oder 2 sein\n", user[ index ] -> id_nummer );
			return(1);
		
		} else if ( user[ index ] -> krv == 1 ) {
		
			if ( user[ index ] -> pvs < 0 || user[ index ] -> pvs > 1 ) {
			
				// return fehler code xy
				printf( "ERROR %f : - der PVS kann nur 0 oder 1 sein\n", user[ index ] -> id_nummer );
				return(1);

			}
		
		} else {
		
			if ( user[ index ] -> pvs != 0 ) {
			
				// return fehler code xy
				printf( "ERROR %f : - wenn KRV 0 oder 2 ist muss PVS 0 sein\n", user[ index ] -> id_nummer ); 
				return(1);
			
			}
		
		}

		user[ index ] -> pkv = inhalt_vom_file[ file_index + 10 ];
		user[ index ] -> kvz = inhalt_vom_file[ file_index + 11 ];

		// pkv Krankenversicherung 0 1 2 privat und privat mit schuss
		// pkv 1 2 braucht pkpv als feld !!!
		if ( user[ index ] -> pkv < 0 || user[ index ] -> pkv > 2 ) {
		
			// return fehler code xy
			printf( "ERROR %f : - wenn PKV kann nur 0, 1 oder 2 sein\n", user[ index ] -> id_nummer );
			return(1);
		
		} else if ( user[ index ] -> pkv != 0 ) {

			if ( user[ index ] -> kvz != 0 ) {
			
				// return fehler code xy
				printf( "ERROR %f : - der KVZ muss 0 sein bei PKV 1 und 2\n", user[ index ] -> id_nummer );
				return(1);
			
			}
		
			user[ index ] -> pkpv = inhalt_vom_file[ file_index + 12 ];
		
		} else {
		
			if ( user[ index ] -> kvz == 0 ) {
			
				// return fehler code xy
				printf( "ERROR %f : - der KVZ muss gesetzt sein bei PKV 0\n", user[ index ] -> id_nummer );
				return(1);
			
			} 
		
		}

		//printf( "--> ID :%f\n", inhalt_vom_file[file_index] );
		//printf( "--> GB :%f\n", inhalt_vom_file[file_index+1] );
		//printf( "--> lzz:%f\n", inhalt_vom_file[file_index+2] );
		//printf( "--> br :%f\n", inhalt_vom_file[file_index+3] );
		//printf( "--> vb :%f\n", inhalt_vom_file[file_index+4] );
		//printf( "--> stk:%f\n", inhalt_vom_file[file_index+5] );
		//printf( "--> zkf:%f\n", inhalt_vom_file[file_index+6] );
		//printf( "--> r  :%f\n", inhalt_vom_file[file_index+7] );
		//printf( "--> krv:%f\n", inhalt_vom_file[file_index+8] );
		//printf( "--> pvs:%f\n", inhalt_vom_file[file_index+9] );
		//printf( "--> pkv:%f\n", inhalt_vom_file[file_index+10] );
		//printf( "--> kvz:%f\n", inhalt_vom_file[file_index+11] );

		//printf( "--> ID :%ld\n", user[ index ] -> id_nummer );
		//printf( "--> GB :%d\n", user[ index ] -> ajahr );
		//printf( "--> lzz:%d\n", user[ index ] -> lzz );
		//printf( "--> br :%ld\n", user[ index ] -> re4 );
		//printf( "--> vb :%ld\n", user[ index ] -> vbez );
		//printf( "--> stk:%d\n", user[ index ] -> stkl );
		//printf( "--> zkf:%f\n", user[ index ] -> zkf );
		//printf( "--> r  :%d\n", user[ index ] -> r );
		//printf( "--> krv:%d\n", user[ index ] -> krv );
		//printf( "--> pvs:%d\n", user[ index ] -> pvs );
		//printf( "--> pkv:%d\n", user[ index ] -> pkv );
		//printf( "--> kvz:%f\n", user[ index ] -> kvz );

		// return zurück geben mit selbst ausgedachten return fehlercode zb 0 fehler frei 1 ein parameter war falsch etc
	
	}

	return(0);

} 

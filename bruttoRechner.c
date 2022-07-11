#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

#include "user_daten.h"

static int opt_auto, opt_manuell, opt_file, opt_spooldir;
static FILE *file_users;

static char *PGM, *file_name;
static char *spooldir = "/tmp";

extern char *eingabe( void );
extern bool kontrolle_der_eingabe( char eingabe[] );

extern struct user_daten* user_daten_new( void );

extern void lr_19_MW( struct user_daten *user );
extern void sv_19_MW( struct user_daten *user );
extern void kst_19_MW( struct user_daten *user );
extern void sum_19_MW( struct user_daten *user );

extern double abrunden_double( int wo, double was );
extern int getfile_size( FILE *file );
extern int lr_parameter_pruefung( struct user_daten *user[], int user_length, double inhalt_vom_file[] );

static void usage( void );

static int process_arguments( int, char *[] );
static int process( void );

static void usage( void ){

	fprintf( stderr, "Usage: %s [options] for bruttoRechner\n", PGM );
	fprintf( stderr, "Options:\n" 
			 "\t-m Manueller Modus für Eingabe\n"
			 "\t-a Automatisierter Modus -f ist dann pflicht\n"
			 "\t-f Filename\n"
	      		 "\t-S spooldir ( default: '/tmp' )\n" );

}

int main ( int argc, char *argv[] ) {

	PGM = argv[0];
	file_name = NULL;

	if ( process_arguments( argc, argv ) ) {
	
		usage();
		goto leave;
	
	}

	if ( opt_manuell == 1 && opt_auto == 1 ) {
	
		printf( "Es können nicht beide Optionen gleichzeitig AKTIV sein( -m und -a )\n" );
		goto leave;

	}
	
	if ( process() ) {
	
		goto leave;
	
	}

leave:

	exit(1);

}

static int process_arguments( int argc, char *argv[] ) {

	int opt;

	while ( ( opt = getopt( argc, argv, "maf:S:" ) ) != EOF ) {
	
		switch( opt ) {
		
			case 'm' :
				printf( "Manueller Modus\n" );
				opt_manuell = 1;
				break;
			case 'a' :
				printf( "Auto Modus\n" );
				opt_auto = 1;
				break;
			case 'f' :
				printf( "Filename %s \n", optarg );
				opt_file = 1;
				file_name = optarg;
				break;
			case 'S' :
				printf( "Spooldir %s \n", optarg );
				opt_spooldir = 1;
				spooldir = optarg;
				break;
			default :
				printf( "Manueller Modus Aktiviert weil fehlender Option\n" );
				opt_manuell = 1;
				break;

		}

	}

	if ( opt_auto == 1 || opt_manuell == 1 ) {
	
		return(0);
	
	}

	return(1);

}

static int process( void ) {

	if ( opt_auto == 1 ) {
	
		if ( opt_auto == 1 && file_name == NULL ) {
	
			printf( "Bitte geben Sie im Auto-Modus die Option -f Filename an\n" );
			usage();
			return(1);
	
		}

		file_users = fopen( file_name , "r" );

		if ( file_users == NULL ) {
	
			printf( "Datei konnte NICHT geoeffnet werden. \n" );
			return(1);
	
		}

		int file_size = getfile_size( file_users );	
		double inhalt_vom_file[file_size];
	
		printf( "%d -erster-:  \n", file_size );

		if ( file_size % 13 != 0 ) {
		
			printf( "Die Daten sind nicht im Format Programm wird Beendet\n" );
			fclose( file_users );
			return(1);
		
		}

		char tmp[2550];
		int file_index = 0; 
	
		printf( "Datei konnte geoeffnet werden. \n" );
		
		while ( fscanf( file_users, "%s", tmp ) != EOF ) {
	
			inhalt_vom_file[file_index] = atof( tmp );

			file_index++;

		}

		// Datei schliessen
		fclose( file_users );
	
		// eintragungen in das Struct user
		int struct_size = file_index/13;
		struct user_daten *file_user[struct_size];
		file_user[0] = user_daten_new();

		// file controlle
		int fehlercode;
		fehlercode = lr_parameter_pruefung( file_user, struct_size, inhalt_vom_file );

		if ( fehlercode == 1 ) {
		
			return(1);
		
		}

		char file_folder[9999] = "";

		strcat( file_folder, spooldir );
		strcat( file_folder, "/auto_modus.txt" );

		file_users = fopen( file_folder, "w+" );

		for ( int index = 0; index < struct_size; index++ ) {
		
			lr_19_MW( file_user[ index ] );
			kst_19_MW( file_user[ index ] );
			sv_19_MW( file_user[ index ] );
			sum_19_MW( file_user[ index ] );
		
			fprintf( file_users, " >>-->>-- - %f - ID Nummer --<<--<< \n", file_user[ index ] -> id_nummer );
			fprintf( file_users, " >>-->>-- - %d - GB Jahr --<<--<< \n", file_user[ index ] -> ajahr );
			fprintf( file_users, " >>-->>-- - %f - LSTLZZ  --<<--<< \n", file_user[ index ] -> lstlzz );
			fprintf( file_users, " >>-->>-- - %f - SOLI --<<--<< \n", file_user[ index ] -> solzlzz );
			fprintf( file_users, " >>-->>-- - %f - Kirche --<<--<< \n", file_user[ index ] -> kst );
			fprintf( file_users, " >>-->>-- - %f - Rente --<<--<< \n", file_user[ index ] -> rv );
			fprintf( file_users, " >>-->>-- - %f - Arlose --<<--<< \n", file_user[ index ] -> av );
			fprintf( file_users, " >>-->>-- - %f - Kranken --<<--<< \n", file_user[ index ] -> kv );
			fprintf( file_users, " >>-->>-- - %f - Pflege AN --<<--<< \n", file_user[ index ] -> pv_an );
			fprintf( file_users, " >>-->>-- - %f - Pflege AG --<<--<< \n", file_user[ index ] -> pv_ag );
			fprintf( file_users, " >>-->>-- - %f - Gesamt_ST --<<--<< \n", file_user[ index ] -> gesamt_st );
			fprintf( file_users, " >>-->>-- - %f - sum_so_an --<<--<< \n", file_user[ index ] -> sum_sozialv_an );
			fprintf( file_users, " >>-->>-- - %f - sum_so_ag --<<--<< \n", file_user[ index ] -> sum_sozialv_ag );
			fprintf( file_users, " >>-->>-- - %f - netto_lohn --<<--<< \n", file_user[ index ] -> netto_lohn );
			fprintf( file_users, " >>-->>-- - %f - gesamt_belast --<<--<< \n", file_user[ index ] -> gesamt_belast_ag );

		}

		fclose( file_users );

	} 
	else if ( opt_manuell == 1 ) {

		struct user_daten *user;
		user = user_daten_new();

		char *_eingabe;
		bool eingabeTest = true;

		do {
	
			printf( "Bitte geben Sie Ihr Geburtsjahr ein : ---> " );
			_eingabe = eingabe();
			eingabeTest = kontrolle_der_eingabe( _eingabe );
	
		} while ( eingabeTest );
	
		user -> ajahr = abrunden_double( 0, atof( _eingabe ) );
		free( _eingabe );

		// ajahr muss noch weiter verarbeitet werden wegen ALTER1 etc
		user -> alter1 = 0;
		if ( 2019 - user -> ajahr > 64 ) {
	
			user -> alter1 = 1;
	
		}

		do {
	
			printf( "Soll in Monat( 1 ) oder in Jahren( 0 ) berechnet werden : ---> " );
			_eingabe = eingabe();
			eingabeTest = kontrolle_der_eingabe( _eingabe );
		
			if ( atoi( _eingabe ) != 0 && atoi( _eingabe ) != 1 ) {
		
				eingabeTest = true;
		
			}
	
		} while ( eingabeTest );

		if ( atoi( _eingabe ) == 1 ) {

			free( _eingabe );
			user -> lzz = 2;

			// Monat
			do {
		
				printf( "Geben Sie nun ihr BruttoLohn im Monat an : ---> " );
				_eingabe = eingabe();
				eingabeTest = kontrolle_der_eingabe( _eingabe );
		
			} while ( eingabeTest );

			user -> re4 = abrunden_double( 2, atof( _eingabe ) ) * 100;
			user -> jre4 = abrunden_double( 2, ( user -> re4 * 12 ) );
	
		} else {
	
			free( _eingabe );

			// Jahr
			do {
		
				printf( "Geben Sie nun ihr BruttoLohn im Jahr an : ---> " );
				_eingabe = eingabe();
				eingabeTest = kontrolle_der_eingabe( _eingabe );
		
			} while ( eingabeTest );
	
			user -> re4 = abrunden_double( 2, atof( _eingabe ) ) * 100;
			user -> jre4 = user -> re4;
	
		}

		free( _eingabe );

		// wenn was tun dann hier für RE4

		do {
	
			printf( "davon Versorgungsbezüge : ---> " );
			_eingabe = eingabe();
			eingabeTest = kontrolle_der_eingabe( _eingabe );

			if ( ( atof( _eingabe ) * 100 ) >= user -> re4 ) {
		
				eingabeTest = true;	
		
			}
	
		} while ( eingabeTest );

		user -> vbez = abrunden_double( 2, atof( _eingabe ) ) * 100;
		free( _eingabe );

		// wenn was tun dann hier für VBEZ
	
		do {
	
			printf( "Welche Steuerklassen haben Sie : ---> " );
			_eingabe = eingabe();
			eingabeTest = kontrolle_der_eingabe( _eingabe );

			if ( atoi( _eingabe ) < 1 || atoi( _eingabe ) > 6 ) { 
		
				eingabeTest = true;
		
			}
	
		} while ( eingabeTest );

		user -> stkl = (int) abrunden_double( 0, atof( _eingabe ) );
		free( _eingabe );

		// wenn was tun dann hier für STKLl

		if ( user -> stkl != 1 ) {	

			do {
	
				printf( "Wie viele Kinder haben Sie : ---> " );
				_eingabe = eingabe();
				eingabeTest = kontrolle_der_eingabe( _eingabe );

				if ( user -> stkl == 2 && atof( _eingabe ) <= 0 ) {
		
					eingabeTest = true;
		
				}
	
			} while ( eingabeTest );

			user -> zkf = abrunden_double( 1, atof( _eingabe ) );
			free( _eingabe );

		}

		// wenn was tun dann hier für ZKF
	
		user -> pvz = 0;

		if ( user -> zkf == 0.0 && 2019 - user -> ajahr > 23 ) {
	
			user -> pvz = 1;
	
		}

		do {
	
			printf( "Sind Sie in der Kirche ( Ja = 1 / Nein = 0 ) : ---> " );
			_eingabe = eingabe();
			eingabeTest = kontrolle_der_eingabe( _eingabe );
	
		} while ( eingabeTest );
	
		user -> r = abrunden_double( 0, atof( _eingabe ) );
		free( _eingabe );

		// wenn was tun dann hier für R
	
		do {  
	
			printf( "Welche gesetzliche Rentenversicherung sind Sie (für West 0 / für Ost 1 / für alles andere 2) : ---> " );
			_eingabe = eingabe();
			eingabeTest = kontrolle_der_eingabe( _eingabe );

			if ( atoi( _eingabe ) != 0 && atoi( _eingabe ) != 1 && atoi( _eingabe ) != 2 ) {
		
				eingabeTest = true;
		
			}	
	
		} while ( eingabeTest );

		user -> krv = abrunden_double( 0, atof( _eingabe ) );
		free( _eingabe );

		// wenn was tun dann hier für KRV

		if ( user -> krv == 1 ) {
	
			do {
		
				printf( "Wohnen Sie in Sachen ( für Ja 1 / für Nein 0 ) : ---> " );
				_eingabe = eingabe();
				eingabeTest = kontrolle_der_eingabe( _eingabe );

				if ( atoi( _eingabe ) != 0 && atoi( _eingabe ) != 1 ) {
			
					eingabeTest = true;
			
				}
		
			} while ( eingabeTest );

			user -> pvs = abrunden_double( 0, atof( _eingabe ) );
			free( _eingabe );
	
		}
	
		do {
	
			printf( "Sind Sie gesetzlich Krankenversichert ( 0 ) / Privat ohne zuschuss ( 1 ) / Privat mit zuschuss ( 2 ) : ---> " );
			_eingabe = eingabe();
			eingabeTest = kontrolle_der_eingabe( _eingabe );

			if ( atoi( _eingabe ) != 0 && atoi( _eingabe ) != 1 && atoi( _eingabe ) != 2 ) {
		
				eingabeTest = true;
		
			}
	
		} while ( eingabeTest );

		user -> pkv = abrunden_double( 0, atof( _eingabe ) );
		free( _eingabe );

		// wenn was tun dann hier für PKV
		//
	
		if ( user -> pkv == 0 ) {
	
			do {

				printf( "Wie hoch ist der Zusatzbeitragssatz der gesetzlichen Krankenversicherung : ---> " );
				_eingabe = eingabe();
				eingabeTest = kontrolle_der_eingabe( _eingabe );

				user -> kvz = atof( _eingabe );
				free( _eingabe );

			} while ( eingabeTest );

		} else if ( user -> pkv == 1 || user -> pkv == 2 ) {
		
			do {

				printf( "Wie hoch ist der Privat Versicherungsbeitrag : ---> " );
				_eingabe = eingabe();
				eingabeTest = kontrolle_der_eingabe( _eingabe );

				double pkpv = atof( _eingabe ) * 100 ;
				user -> pkpv = pkpv;

				printf( "%f \n", pkpv );
		
			} while ( eingabeTest );

		}

		printf( "PVZ - %d - \n", user -> pvz );

		char file_folder[9999] = "";

		strcat( file_folder, spooldir );
		strcat( file_folder, "/manu_modus.txt" );

		file_users = fopen( file_folder , "w+" );

		lr_19_MW( user );
		kst_19_MW( user );
		sv_19_MW( user );
		sum_19_MW( user );

		fprintf( file_users, " >>-->>-- - %f - ID Nummer --<<--<< \n", user -> id_nummer );
		fprintf( file_users, " >>-->>-- - %d - GB Jahr --<<--<< \n", user -> ajahr );
		fprintf( file_users, " >>-->>-- - %f - LSTLZZ --<<--<< \n", user -> lstlzz );
		fprintf( file_users, " >>-->>-- - %f - SOLI --<<--<< \n", user -> solzlzz );
		fprintf( file_users, " >>-->>-- - %f - Kirche --<<--<< \n", user -> kst );
		fprintf( file_users, " >>-->>-- - %f - Rente --<<--<< \n", user -> rv );
		fprintf( file_users, " >>-->>-- - %f - Arlose --<<--<< \n", user -> av );
		fprintf( file_users, " >>-->>-- - %f - Kranken --<<--<< \n", user -> kv );
		fprintf( file_users, " >>-->>-- - %f - Pflege AN --<<--<< \n", user -> pv_an );
		fprintf( file_users, " >>-->>-- - %f - Pflege AG --<<--<< \n", user -> pv_ag );
		fprintf( file_users, " >>-->>-- - %f - Gesamt_ST --<<--<< \n", user -> gesamt_st );
		fprintf( file_users, " >>-->>-- - %f - sum_so_an --<<--<< \n", user -> sum_sozialv_an );
		fprintf( file_users, " >>-->>-- - %f - sum_so_ag --<<--<< \n", user -> sum_sozialv_ag );
		fprintf( file_users, " >>-->>-- - %f - netto_lohn --<<--<< \n", user -> netto_lohn );
		fprintf( file_users, " >>-->>-- - %f - gesamt_belast --<<--<< \n", user -> gesamt_belast_ag );

		fclose( file_users );

	}

	return(0);

}

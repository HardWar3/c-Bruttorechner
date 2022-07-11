#include <stdio.h>
#include <stdlib.h>

int getfile_size( FILE *file );

int getfile_size( FILE *file ) {

	int index = 0;
	char tmp[255];

	while ( fscanf( file, "%s", tmp ) != EOF ) {
	
		index++;
	
	}

	fseek( file, 0, SEEK_SET );

	return index;

}

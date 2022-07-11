#include <stdio.h>
#include <stdlib.h>

double abrunden_double( int wo, double was );

double abrunden_double( int wo, double was ) {
	
	double result;
	double vorgang_1;
	double vorgang_2;

	long komma[7] = { 1.0, 10.0, 100.0, 1000.0, 10000.0, 100000.0, 1000000.0 };

	if ( wo < 7 ) {
		
		vorgang_1 = (long) ( was * komma[wo] );

		vorgang_2 = ( vorgang_1 / komma[wo] ); 

		result = vorgang_2;
	
		return result;

	} else {
	
		return was;
		
	}

}

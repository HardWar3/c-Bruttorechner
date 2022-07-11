#include <stdio.h>
#include <stdlib.h>

double aufrunden_double( int wo, double was );

double aufrunden_double( int wo, double was ) {

	double result;
	double vorgang_1;
	double vorgang_2;

	long komma[7] = { 1.0,10.0,100.0,1000.0,10000.0,100000.0,10000000.0 };

	if ( wo < 7 ) {
	
		vorgang_1 = (long) ( ( was + 0.99 ) * komma[wo] );

		vorgang_2 = ( vorgang_1 / komma[wo] );

		result = vorgang_2;

		return result;
	
	} else {
	
		return was;
	
	}

}

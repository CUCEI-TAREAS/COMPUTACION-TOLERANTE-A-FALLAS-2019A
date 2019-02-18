//#include <cmath>
#include <iostream>
#include <list>

#include "happy_number.hpp"

#define DEC_EXP 10

using namespace std;
/*
7 es un número feliz, ya que:
    72 = 49
    42 + 92 = 97
    92 + 72 = 130
    12 + 32 + 02 = 10
    12 + 02 = 1.

Si n no es feliz la suma de los cuadrados entrará en un bucle (de periodo 8):
    4, 16, 37, 58, 89, 145, 42, 20, 4,...
*/

long long isMagicNumber(long long number){

	long long square;
	long long first_number = square / 10;

	cout<<"origin: "<< number << endl;

	square = number * number;
	cout<<"square: "<< square << endl;

// COMMIT POINT
	cout<<"first_number: "<< first_number << endl;

	long long second_number = square - ( first_number * 10 );
	return second_number;

	// criterio de paro
	// la suma de los cuadrados de cada digito suma 1 ? 

		// si > TERMINAR NUMERO FELIZ

		// no > NO ES UN NUMERO FELIZ 
}


list <int> splitNumber( long long number ){

	long long divisor = DEC_EXP; // mutplicate divisor por 10 siempre

	list <int> numbers;

	if(number < DEC_EXP){
		numbers.push_back(number);
		return numbers;
	}

	long long aux = number;

	while( aux < DEC_EXP ){

		long long result = number / divisor;

		numbers.push_back(result);
		aux = aux - ( result * divisor ) ;

		if( aux < DEC_EXP ){
			numbers.push_back(aux);
			return numbers;
		}
	}
}

#include <iostream>
#include <list>

#define DEC_EXP 10
#define DEC_EXIT 1

using namespace std;
/*
Si n no es feliz la suma de los cuadrados entrará en un bucle (de periodo 8):
    4, 16, 37, 58, 89, 145, 42, 20, 4,...
*/

list <int> splitNumber( long long number ){

	if ( number < 0 ){
		cout<<"negative number ... converting to positive" << endl;
		number = number * -1;
	}

	long long divisor = DEC_EXP; // mutplicate divisor por 10 siempre

	list<int> numbers;

	if(number == DEC_EXP){
		numbers.push_back(1);
		numbers.push_back(0);
		return numbers;
	}
	else if(number < DEC_EXP){
		numbers.push_back(number);
		return numbers;
	}

	long long aux = number;
	

	while( aux > divisor ){

		long long result = number / divisor;

		numbers = splitNumber(result);
		aux = aux - ( result * divisor ) ;

		if( aux < DEC_EXP ){
			numbers.push_back(aux);
			return numbers;
		}
	}
	//cout<<numbers;
	return numbers;
}

unsigned long addSquaredNumbers(list<int> number_list){
	unsigned long value = 0;
	for ( list<int>::iterator it = number_list.begin(); it != number_list.end(); it++){
		value += (*it) * (*it);
	}
	return value;
}

bool isMagicNumber(long long number){

	list<int> splitted;
	unsigned long long aux;
	unsigned long long square = number * number;
	aux = addSquaredNumbers(splitNumber(square));
	cout << aux <<endl;

	while(aux != DEC_EXIT ){
	
		aux = addSquaredNumbers(splitNumber(aux));
		cout << aux <<endl;
	
	}

	//cout<<"origin: "<< number << endl;
	//cout<<"square: "<< square << endl;
}

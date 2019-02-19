#include <iostream>
#include <list>

#define DEC_EXP 10
#define DEC_EXIT 1

#define UNHAPPY_1 4
#define UNHAPPY_2 16
#define UNHAPPY_3 37
#define UNHAPPY_4 58
#define UNHAPPY_5 89
#define UNHAPPY_6 145
#define UNHAPPY_7 42
#define UNHAPPY_8 20
#define UNHAPPY_9 4

#define UNHAPPY_1_comprobation 0
#define UNHAPPY_2_comprobation 1
#define UNHAPPY_3_comprobation 2
#define UNHAPPY_4_comprobation 3
#define UNHAPPY_5_comprobation 4
#define UNHAPPY_6_comprobation 5
#define UNHAPPY_7_comprobation 6
#define UNHAPPY_8_comprobation 7
#define UNHAPPY_9_comprobation 8

using namespace std;

list <int> splitNumber( long long number ){

	if ( number < 0 ){
		cout<<"negative number ... converting to positive" << endl;
		number = number * -1;
	}

	long long divisor = DEC_EXP; // mutplicate divisor por 10 siempre

	list<int> numbers;

	if(number == DEC_EXP){
		numbers.push_front(0);
		numbers.push_front(1);
		return numbers;
	}
	else if(number < DEC_EXP){
		numbers.push_front(number);
		return numbers;
	}

	long long aux = number;

	while( aux > divisor ){

		long long result = aux / divisor;

		numbers = splitNumber(result);
		aux = aux - ( result * divisor ) ;

		if(aux == 0){
			numbers.push_back(0);
			return numbers;
		}
		else if( aux < DEC_EXP ){
			numbers.push_back(aux);
			return numbers;
		}
	}
	return numbers;
}

unsigned long addSquaredNumbers(list<int> number_list){
	unsigned long value = 0;
	for ( list<int>::iterator it = number_list.begin(); it != number_list.end(); it++){
		value += (*it) * (*it);
	}
	return value;
}

bool isMagicNumber(long long number, bool print = false){

	if(number == 0)
		return false;

	list<int> splitted;
	unsigned long long aux;

	if (print)
		cout<<"\t ORIGIN:\t\t"<< number << endl;

	aux = addSquaredNumbers(splitNumber(number));

	if (print)
		cout <<"\t THEN:\t\t"<< aux <<endl;

	unsigned char unhappy = UNHAPPY_1_comprobation;

	while(aux != DEC_EXIT ){
		//Si n no es feliz la suma de los cuadrados entrará en un bucle (de periodo 8):
		// 4, 16, 37, 58, 89, 145, 42, 20, 4,...
	
		if ( aux == UNHAPPY_1 and unhappy == UNHAPPY_1_comprobation){
			// like unhappy number
			unhappy++;
		}
		else if ( aux == UNHAPPY_2 and unhappy == UNHAPPY_2_comprobation){
			unhappy++;
		}
		else if ( aux == UNHAPPY_3 and unhappy == UNHAPPY_3_comprobation){
			unhappy++;
		}
		else if ( aux == UNHAPPY_4 and unhappy == UNHAPPY_4_comprobation){
			unhappy++;
		}
		else if ( aux == UNHAPPY_5 and unhappy == UNHAPPY_5_comprobation){
			unhappy++;
		}
		else if ( aux == UNHAPPY_6 and unhappy == UNHAPPY_6_comprobation){
			unhappy++;
		}
		else if ( aux == UNHAPPY_7 and unhappy == UNHAPPY_7_comprobation){
			unhappy++;
		}
		else if ( aux == UNHAPPY_8 and unhappy == UNHAPPY_8_comprobation){
			unhappy++;
		}
		else if ( aux == UNHAPPY_9 and unhappy == UNHAPPY_9_comprobation){
			// it is unhappy
			return false;
		}
		else {
			unhappy = UNHAPPY_1_comprobation;
		}
		aux = addSquaredNumbers(splitNumber(aux));

		if (print)
			cout <<"\t THEN:\t\t"<< aux <<endl;
	}
	return true;
}

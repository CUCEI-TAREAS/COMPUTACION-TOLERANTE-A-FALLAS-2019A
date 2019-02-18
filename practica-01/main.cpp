#include <iostream>
#include <cstdio>
#include <list>

#include "happy_number.hpp"

using namespace std;

int main(){
	list<int> hola;

	//cout<<isMagicNumber(7)<<endl;
	hola = splitNumber(-9087654321);

	for (std::list<int>::iterator  it = hola.begin(); it!= hola.end(); ++it)
		cout<< *it << endl;

	exit(EXIT_SUCCESS);
}

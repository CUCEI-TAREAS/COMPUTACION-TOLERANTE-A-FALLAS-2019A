#include <iostream>
#include <cstdio>
#include <list>

#include "happy_number.hpp"

using namespace std;

int main(){
	list<int> hola;

	cout<<isMagicNumber(7)<<endl;
	//cout<<isMagicNumber(998)<<endl;
	//hola = splitNumber(998);

	for (std::list<int>::iterator  it = hola.begin(); it!= hola.end(); ++it)
		cout<< *it << endl;

	exit(EXIT_SUCCESS);
}

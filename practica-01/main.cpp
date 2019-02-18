#include <iostream>
#include <cstdio>
#include <list>

#include "happy_number.hpp"

using namespace std;

int main(){
	list <int> hola;

	cout<<isMagicNumber(7);
	hola = sliptNumber(14);

	for (auto it = std::begin(hola); it!=std::end(hola); ++it)
		cout<<*it << endl;
	exit(EXIT_SUCCESS);
}

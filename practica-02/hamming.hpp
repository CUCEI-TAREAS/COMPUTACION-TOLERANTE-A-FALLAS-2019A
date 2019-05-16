#ifndef HAMMING_H_INCLUDED
#define HAMMING_H_INCLUDED

#include <list>

class Hamming {

private:
	std::list<short> total_bits; // parity_bits, data_bits;

public:
	Hamming();
	Hamming( std::list<short> ); // create Hamming object from a Hamming code
	~Hamming();

		

		
};

#endif // HAMMING_H_INCLUDED

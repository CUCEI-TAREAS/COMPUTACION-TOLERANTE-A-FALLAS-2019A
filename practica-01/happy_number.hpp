#ifndef __INCLUDE_HAPPY_NUMBER_HPP__
#define __INCLUDE_HAPPY_NUMBER_HPP__

#include <list>

bool isMagicNumberDirectly(std::list <int>, bool=false);
bool isMagicNumber(unsigned long long, bool=false);
std::list <int> splitNumber( long long);
unsigned long long addSquaredNumbers(std::list <int>);
int estimateTime(long long);

#endif

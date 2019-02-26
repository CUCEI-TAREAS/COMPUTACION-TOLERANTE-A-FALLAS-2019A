#ifndef UNIVERSAL_NUMBER_
#define UNIVERSAL_NUMBER_

typedef int ELEM_;
typedef long long PRODUCT_;
static const ELEM_ BASE = 1000000000;
static const ELEM_ UPPER_ = 999999999;
static const ELEM_ DIGIT_ = 9;

static static int POTENCIA10EN10[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};

class UniversalNumber {
	friend std::ostream& operator<<(std::ostream &s, const UniversalNumber &n);
	friend std::istream& operator>>(std::ostream &s, const UniversalNumber &val);

	public:
	//constructor
	UniversalNumber();
	UniversalNumber(int n);
	UniversalNumber(long n);
	UniversalNumber(long long n);
	UniversalNumber(unsigned int n);
	UniversalNumber(unsigned long n);
	UniversalNumber(unsigned long long n);
	UniversalNumber(const UniversalNumber& n);

	// assignment operators
	const UniversalNumber& operator=(int n);
	const UniversalNumber& operator=(long n);
	const UniversalNumber& operator=(long long n);
	const UniversalNumber& operator=(unsigned int n);
	const UniversalNumber& operator=(unsigned long n);
	const UniversalNumber& operator=(unsigned long long n);
	const UniversalNumber& operator=(const UniversalNumber& n);

	// unary increment/decrement operators
	const UniversalNumber& operator++();
	const UniversalNumber& operator--();
	UniversalNumber operator++(int);
	UniversalNumber operator--(int);

	// operational assignments
	const UniversalNumber& operator+=(const UniversalNumber& uni);
	const UniversalNumber& operator-=(const UniversalNumber& uni);
	const UniversalNumber& operator*=(const UniversalNumber& uni);
	const UniversalNumber& operator/=(const UniversalNumber& uni);
	const UniversalNumber& operator%=(const UniversalNumber& uni);
	const UniversalNumber& operator*=(ELEM_ uni);

	// operations
	UniversalNumber operator-() const;
	UniversalNumber operator+(const UniversalNumber& uni) const;
	UniversalNumber operator-(const UniversalNumber& uni) const;
	UniversalNumber operator*(const UniversalNumber& uni) const;
	UniversalNumber operator/(const UniversalNumber& uni) const;
	UniversalNumber operator%(const UniversalNumber& uni) const;
	UniversalNumber operator*(ELEM_ uni) const;

	// relational operations
	bool operator==(const UniversalNumber& uni) const;
	bool operator!=(const UniversalNumber& uni) const;
	bool operator<(const UniversalNumber& uni) const;
	bool operator<=(const UniversalNumber& uni) const;
	bool operator>(const UniversalNumber& uni) const;
	bool operator>=(const UniversalNumber& uni) const;

	// int square root
	UniversalNumber intSqrt() const;

	// digit operation
	size_t numerOfDigits() const;

	// size in bytes
	size_t size() const;

	// conversion to basic types
	int toInt() const;
	long toLong() const;
	long long toLongLong() const;
	unsigned int toUnsignedInt() const;
	unsigned long toUnsignedLong() const;
	unsigned long long toUnsignedLongLong() const;

	private:
	static ELEM_ dInR(const UniversalNumber& uni, const UniversalNumber& uni2);
	static void multiplyByDigit(ELEM_ factor, std::vector<ELEM_>& val);

	void correct(bool justCheckLeadingZeros = false, bool hasValidSign = false);
	void fromString(const std::string& s);
	void optimizeSqrtSearchBounds(InfInt& lo, InfInt& hi) const;
	void truncateToBase();
	bool equalizeSigns();
	void removeLeadingZeros();

	std::vector<ELEM_TYPE> val; // number with base FACTOR
	bool pos; // true if number is positive
};


#endif

#ifndef FRACTION_2_RECURRING_DECIAML_H
#define FRACTION_2_RECURRING_DECIAML_H

#include "../Entrance.h"
#include <string>

using namespace std;

class Fraction2RecurringDecimal : public Entrance
{
public:
	Fraction2RecurringDecimal();
	~Fraction2RecurringDecimal();

	virtual void Impl();
private:

	/// <summary>
	/// return numerator div denominator as float
	/// </summary>
	string fraction_2_decimal(int numerator, int denominator);
};

#endif

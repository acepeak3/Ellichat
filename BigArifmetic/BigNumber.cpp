#include "BigNumber.h"

BigNumber::BigNumber()
{
	for (auto digit = digits_.begin(); digit != digits_.end(); digit++)	*digit = 0;
}

BigNumber::BigNumber(const string _numberString)
{
	for (auto digit = digits_.begin(); digit != digits_.end(); digit++)	*digit = 0;

	size_t numberSize = (_numberString.size() - 1) / 8;
	if ((_numberString.size() - 1) % 8 != 0) numberSize++;
	
	for (size_t i = 0; i < numberSize; i++)
	{
		const size_t digitCount = (i * 8 <= _numberString.size() - 8 ? 8 : _numberString.size() - i * 8);
		string digitString = _numberString.substr(_numberString.size() - digitCount - i * 8, digitCount);
		digits_[i] = stoll(digitString, 0, 16);
	}
}

string BigNumber::toString() const
{
	string result;

	for (auto digit = digits_.begin(); digit != digits_.end(); digit++)
	{
		stringstream sstream;
		sstream << hex << *digit;
		
		result = sstream.str() + " " + result;
	}

	return result;
}

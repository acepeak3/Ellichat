#include "BigNumber.h"

BigNumber::BigNumber()
{
	for (auto digit = digits_.begin(); digit != digits_.end(); digit++)	*digit = 0;
}

BigNumber::BigNumber(const std::string _numberString)
{
	for (auto digit = digits_.begin(); digit != digits_.end(); digit++)	*digit = 0;

	size_t
		stringSize = _numberString.size(),
		blockCount = stringSize / 8;

	if (stringSize % 8 != 0) blockCount++;

	size_t startPosition = 0;

	for (size_t i = 0; i < blockCount; i++)
	{
		startPosition += 8;

		size_t digitCount = 8;

		if (startPosition > stringSize)
		{
			startPosition = stringSize;
			digitCount -= ((i + 1) * 8 - stringSize);
		}

		std::string digitString = _numberString.substr(stringSize - startPosition, digitCount);
		digits_[i] = std::stoll(digitString, 0, 16);
	}
}

string BigNumber::toString() const
{
	string result;

	for (auto digit = digits_.begin(); digit != digits_.end(); digit++)
	{
		stringstream sstream;
		sstream << setw(8) << setfill('0') << hex << *digit;
		result = sstream.str() + " " + result;
	}

	return result;
}
#include "BigArifmetic.h"

BigNumber operator +(const BigNumber _number1, const BigNumber _number2)
{
	BigNumber result;
	uint64_t transfer = 0;

	for (size_t i = 0; i < BigNumber::numberSize; i++)
	{
		const uint64_t number = _number1.digits_[i] + _number2.digits_[i] + transfer;
		result.digits_[i] = number & 0x0000ffff;
		transfer = (number & 0xffff0000) >> 32;
	}

	if (transfer) result.digits_[BigNumber::numberSize] = (uint32_t)transfer;
	return result;
}
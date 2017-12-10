#include "BigArifmetic.h"

BigNumber operator +(const BigNumber _number1, const BigNumber _number2)
{
	BigNumber result;
	uint64_t transfer = 0;

	for (size_t i = 0; i < BigNumber::numberSize; i++)
	{
		const uint64_t number = (uint64_t)_number1.digits_[i] + _number2.digits_[i] + transfer;
		result.digits_[i] = number & 0x00000000ffffffff;
		transfer = (number & 0xffffffff00000000) >> 32;
	}

	if (transfer) result.digits_[BigNumber::numberSize] = (uint32_t)transfer;
	return result;
}

BigNumber smallMultiply(const BigNumber _number, const uint32_t _small)
{
	BigNumber result;

	uint64_t transfer = 0;

	for (size_t i = 0; i < BigNumber::numberSize; i++)
	{
		const uint64_t number = (uint64_t)_number.digits_[i] * _small + transfer;
		result.digits_[i] = number & 0x00000000ffffffff;
		transfer = (number & 0xffffffff00000000) >> 32;
	}

	if (transfer) result.digits_[BigNumber::numberSize] = (uint32_t)transfer;

	return result;
}

BigNumber shiftMultiply(const BigNumber _number, const size_t _basePower)
{
	BigNumber result;

	for (int i = BigNumber::numberSize - 1 - _basePower; i >= 0; i--)
	{
		result.digits_[i + _basePower] = _number.digits_[i];
	}

	return result;
}

BigNumber operator *(const BigNumber _number1, const BigNumber _number2)
{
	BigNumber result;

	for (size_t i = 0; i < BigNumber::numberSize; i++)
	{
		const BigNumber tempNumber1 = smallMultiply(_number1, _number2.digits_[i]);
		const BigNumber tempNumber2 = shiftMultiply(tempNumber1, i);
		result = result + tempNumber2;
	}

	return result;
}
#include "BigArifmetic.h"

BigNumber operator +(const BigNumber _number1, const BigNumber _number2)
{
	BigNumber result;
	uint64_t transfer = 0;

	for (size_t i = 0; i < BigNumber::blockCount; i++)
	{
		const uint64_t number = (uint64_t)_number1.blocks_[i] + _number2.blocks_[i] + transfer;
		result.blocks_[i] = number & 0x00000000ffffffff;
		transfer = (number & 0xffffffff00000000) >> 32; // 0 or 1
	}

	if (transfer) result.blocks_[BigNumber::blockCount] = (uint32_t)transfer;
	return result;
}

BigNumber operator-(const BigNumber _number1, const BigNumber _number2)
{
	BigNumber result;
	uint64_t transfer = 0;

	for (size_t i = 0; i < BigNumber::blockCount; i++)
	{
		const uint64_t number = (uint64_t)_number1.blocks_[i] - _number2.blocks_[i] + transfer;
		if (number >= 0)
		{
			result.blocks_[i] = number & 0x00000000ffffffff;
			transfer = 0;
		}
		else
		{
			result.blocks_[i] = (0x0000000100000000 + number) & 0x00000000ffffffff;
			transfer = -1;
		}
	}

	if (transfer) result.blocks_[BigNumber::blockCount] = (uint32_t)transfer;
	return result;
}

BigNumber smallMultiply(const BigNumber _number, const uint32_t _small)
{
	BigNumber result;

	uint64_t transfer = 0;

	for (size_t i = 0; i < BigNumber::blockCount; i++)
	{
		const uint64_t number = (uint64_t)_number.blocks_[i] * _small + transfer;
		result.blocks_[i] = number & 0x00000000ffffffff;
		transfer = (number & 0xffffffff00000000) >> 32;
	}

	if (transfer) result.blocks_[BigNumber::blockCount] = (uint32_t)transfer;

	return result;
}

BigNumber shiftMultiply(const BigNumber _number, const size_t _basePower)
{
	BigNumber result;

	for (int i = BigNumber::blockCount - 1 - _basePower; i >= 0; i--)
	{
		result.blocks_[i + _basePower] = _number.blocks_[i];
	}

	return result;
}

BigNumber operator *(const BigNumber _number1, const BigNumber _number2)
{
	BigNumber result;

	for (size_t i = 0; i < BigNumber::blockCount; i++)
	{
		const BigNumber tempNumber1 = smallMultiply(_number1, _number2.blocks_[i]);
		const BigNumber tempNumber2 = shiftMultiply(tempNumber1, i);
		result = result + tempNumber2;
	}

	return result;
}



BigNumber operator %(const BigNumber _number1, const BigNumber _number2)
{
	BigNumber
		number1 = _number1,
		number2 = _number2;

	while (!(number1 < number2))
	{
		size_t
			highestBlockIndex1,
			highestBlockIndex2;

		const uint32_t
			highBlock1 = _number1.highestBlock(highestBlockIndex1),
			highBlock2 = _number2.highestBlock(highestBlockIndex2),
			blockRatio = highBlock1 / highBlock2;

		if (highestBlockIndex1 < highestBlockIndex2) throw;

		const size_t blockShift = highestBlockIndex1 - highestBlockIndex2;

		BigNumber diff = shiftMultiply(smallMultiply(number2, blockRatio), highestBlockIndex1 - highestBlockIndex2);

		number1 = number1 - diff;
	}
	return number1;
}

bool operator ==(const BigNumber _number1, const BigNumber _number2)
{
	size_t i = 0;
	while ((i < BigNumber::blockCount) && (_number1.blocks_[i] == _number2.blocks_[i])) i++;

	return (i==BigNumber::blockCount);
}

bool operator >(const BigNumber _number1, const BigNumber _number2)
{
	size_t i = BigNumber::blockCount;
	while ((i >= 0) && (_number1.blocks_[i] == _number2.blocks_[i])) i--;

	return ((i >= 0) && (_number1.blocks_[i] > _number2.blocks_[i]));
}

bool operator <(const BigNumber _number1, const BigNumber _number2)
{
	size_t i = BigNumber::blockCount;
	while ((i >= 0) && (_number1.blocks_[i] == _number2.blocks_[i])) i--;

	return ((i >= 0) && (_number1.blocks_[i] < _number2.blocks_[i]));
}

#include "BigArifmetic.h"

BigNumber operator +(const BigNumber _number1, const BigNumber _number2)
{
	BigNumber result;

	uint64_t transfer = 0;

	for (size_t i = 0; i < 2 * BigNumber::blockCount; i++)
	{
		const uint64_t number = (uint64_t)_number1.blocks_[i] + _number2.blocks_[i] + transfer;
		result.blocks_[i] = number & 0x00000000ffffffff;
		transfer = (number & 0xffffffff00000000) >> 32; // 0 or 1
	}

	if (transfer) result.blocks_[BigNumber::blockCount] = (uint32_t)transfer;

	return result;
}

BigNumber operator -(const BigNumber _number1, const BigNumber _number2) // _number1 >= _number2 !
{
	BigNumber result;

	int64_t transfer = 0;

	for (size_t i = 0; i < 2 * BigNumber::blockCount; i++)
	{
		const int64_t number = (int64_t)_number1.blocks_[i] - _number2.blocks_[i] + transfer;

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

	for (size_t i = 0; i < 2 * BigNumber::blockCount; i++)
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

	for (int/*important!!!*/ i = 2 * BigNumber::blockCount - 1 - _basePower; i >= 0; i--)
	{
		result.blocks_[i + _basePower] = _number.blocks_[i];
	}

	return result;
}

BigNumber operator *(const BigNumber _number1, const BigNumber _number2)
{
	BigNumber result;

	for (size_t i = 0; i < 2 * BigNumber::blockCount; i++)
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

	while (number1 > number2)
	{
		size_t
			highestBlockIndex1,
			highestBlockIndex2;

		const uint32_t
			highBlock1 = number1.highestBlock(highestBlockIndex1),
			highBlock2 = number2.highestBlock(highestBlockIndex2);

		//if (highestBlockIndex1 < highestBlockIndex2) throw;

		uint64_t
			number1highPart = (uint64_t)highBlock1,
			number2highPart = (uint64_t)highBlock2;

		if (highBlock1 != highBlock2)
		{
			number2highPart++;
		}

		if (highBlock1 < highBlock2)
		{
			number1highPart = ((uint64_t)highBlock1 << 32) + number1.blocks_[highestBlockIndex1 - 1];
			highestBlockIndex1--;
		}

		uint64_t highPartRatio = number1highPart / number2highPart;

		const size_t blockShift = highestBlockIndex1 - highestBlockIndex2;

		BigNumber diff = shiftMultiply(smallMultiply(number2, highPartRatio), blockShift);

		if (diff > number1) throw;

		number1 = number1 - diff;
	}

	if (number1 == number2) return BigNumber(0);

	return number1;
}

BigNumber operator /(const BigNumber _number1, const BigNumber _number2)
{
	BigNumber
		number1 = _number1,
		number2 = _number2,
		result;

	while (number1 > number2)
	{
		size_t
			highestBlockIndex1,
			highestBlockIndex2;

		const uint32_t
			highBlock1 = number1.highestBlock(highestBlockIndex1),
			highBlock2 = number2.highestBlock(highestBlockIndex2);

		//if (highestBlockIndex1 < highestBlockIndex2) throw;

		uint64_t
			number1highPart = (uint64_t)highBlock1,
			number2highPart = (uint64_t)highBlock2;

		if (highBlock1 != highBlock2)
		{
			number2highPart++;
		}

		if (highBlock1 < highBlock2)
		{
			number1highPart = ((uint64_t)highBlock1 << 32) + number1.blocks_[highestBlockIndex1 - 1];
			highestBlockIndex1--;
		}

		uint64_t highPartRatio = number1highPart / number2highPart;

		const size_t blockShift = highestBlockIndex1 - highestBlockIndex2;

		BigNumber diff = shiftMultiply(smallMultiply(number2, highPartRatio), blockShift);

		if (diff > number1) throw;

		result = result + shiftMultiply(BigNumber(highPartRatio), blockShift);

		number1 = number1 - diff;
	}

	if (number1 == number2) result = result + BigNumber(1);

	return result;
}

bool operator ==(const BigNumber _number1, const BigNumber _number2)
{
	size_t i = 0;

	while ((i < 2 * BigNumber::blockCount) && (_number1.blocks_[i] == _number2.blocks_[i])) i++;

	return (i == 2 * BigNumber::blockCount);
}

bool operator >(const BigNumber _number1, const BigNumber _number2)
{
	int i = 2 * BigNumber::blockCount - 1;

	while ((i >= 0) && (_number1.blocks_[i] == _number2.blocks_[i])) i--;

	return (i >= 0) && (_number1.blocks_[i] > _number2.blocks_[i]);
}

bool operator <(const BigNumber _number1, const BigNumber _number2)
{
	int i = 2 * BigNumber::blockCount - 1;

	while ((i >= 0) && (_number1.blocks_[i] == _number2.blocks_[i])) i--;

	return (i >= 0) && (_number1.blocks_[i] < _number2.blocks_[i]);
}

BigNumber inverse(const BigNumber _number, const BigNumber _module) //  _number < _module
{
	BigNumber
		n = _number,
		m = _module,
		a(1),
		b(0),
		c(0),
		d(1);

	bool evenStep = true;

	while ((n > BigNumber(1)) && (m > BigNumber(1)))
	{
		if (evenStep)
		{
			const BigNumber k = m / n;
			m = m % n;
			a = a + c * k;
			b = b + d * k;
		}
		else
		{
			const BigNumber k = n / m;
			n = n % m;
			c = c + a * k;
			d = d + b * k;
		}

		evenStep = !evenStep;
	}

	return (evenStep ? d : _module - b);
}

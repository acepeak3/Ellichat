#include "BigNumber.h"

BigNumber::BigNumber()
{
	for (auto block = blocks_.begin(); block != blocks_.end(); block++)	*block = 0;
}

BigNumber::BigNumber(const std::string _numberString)
{
	for (auto block = blocks_.begin(); block != blocks_.end(); block++)	*block = 0;

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
		blocks_[i] = std::stoll(digitString, 0, 16);
	}
}

string BigNumber::toString() const
{
	string result;

	for (auto block = blocks_.begin(); block != blocks_.end(); block++)
	{
		stringstream sstream;
		sstream << setw(8) << setfill('0') << hex << *block;
		result = sstream.str() + " " + result;
	}

	return result;
}

uint32_t BigNumber::highestBlock(size_t &_highestBlockIndex) const
{
	int i = BigNumber::blockCount - 1;

	while ((i >= 0) && (blocks_[i] == 0)) i--;

	_highestBlockIndex = i;

	return (i >= 0 ? blocks_[i] : blocks_[0]);
}
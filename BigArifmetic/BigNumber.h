#pragma once

#include <array>
#include <string>
#include <sstream>
#include <iomanip>

struct BigNumber
{
	static const size_t blockCount = 32;

	std::array<uint32_t, 2 * blockCount> blocks_;

	BigNumber();
	BigNumber(const uint32_t _number);
	BigNumber(const std::string _numberString);

	std::string toString() const;
	uint32_t highestBlock(size_t &_highestBlockIndex) const;
};
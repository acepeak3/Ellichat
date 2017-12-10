#pragma once

#include <array>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

struct BigNumber
{
	BigNumber();
	BigNumber(const string _numberString);
	
	static const size_t blockCount = 32;
	array<uint32_t, 2 * blockCount> blocks_;
	
	string toString() const;
	uint32_t highestBlock(size_t &_highestBlockIndex) const;
};
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
	
	static const size_t numberSize = 32;
	array<uint32_t, 2 * numberSize> digits_;
	string toString() const;
};
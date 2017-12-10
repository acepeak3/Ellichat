#pragma once

#include "BigNumber.h"

BigNumber operator +(const BigNumber _number1, const BigNumber _number2);
BigNumber operator -(const BigNumber _number1, const BigNumber _number2);
BigNumber operator *(const BigNumber _number1, const BigNumber _number2);
BigNumber operator %(const BigNumber _number1, const BigNumber _number2);
BigNumber operator /(const BigNumber _number1, const BigNumber _number2);

bool operator ==(const BigNumber _number1, const BigNumber _number2);
bool operator >(const BigNumber _number1, const BigNumber _number2);
bool operator <(const BigNumber _number1, const BigNumber _number2);

BigNumber inverse(const BigNumber _number, const BigNumber _module); // _number < _module
#pragma once
#include <iostream>
#include "BigNumber.h"

BigNumber operator +(const BigNumber _number1, const BigNumber _number2);
BigNumber operator -(const BigNumber _number1, const BigNumber _number2);
BigNumber operator *(const BigNumber _number1, const BigNumber _number2);

bool operator ==(const BigNumber _number1, const BigNumber _number2);
bool operator >(const BigNumber _number1, const BigNumber _number2);
bool operator <(const BigNumber _number1, const BigNumber _number2);
#include <iostream>
#include "../BigArifmetic/BigArifmetic.h"

int main()
{

	/*
	BigNumber number("543ee4525000000000000000ddddddddddddddddddddd12f");

	std::cout << number.toString() << "\n";
	*/

	/*
	BigNumber
	number1("5555ff6543245465354aaaaddddd45455555ff6543245465354aaaaddddd454545ddddd56654ff33335555ff6543245465354aaaaddddd454545ddddd56654ff333345ddddd56654ff3333"),
	number2("dd11213213250000024545454abcde626eeee52341654dd11213213250000024545454abcde626eeee52341654254523255555554d254523255555554d");

	BigNumber number3 = number1 * number2;

	std::cout << number3.toString() << "\n";
	*/

	/*
	BigNumber
	number1("1000000000000000000000000000000000000000000000000000000000000"),
	number2("1");

	BigNumber number3 = number1 - number2;

	std::cout << number3.toString() << "\n";
	*/
	/*
	BigNumber
	number1("2544647abcccc242ff881118dee111111111111111e"),
	number2("654445dfdfdfdf4545fdf45fd555"),
	number3("77777777777");

	BigNumber number4 = number1 * number2 + number3;

	std::cout << number4.toString() << "\n";

	BigNumber number5 = number4 % number2;

	std::cout << number5.toString() << "\n";
	*/

	/*
	BigNumber
	number1("55ffff2332334888891dacb4122214"),
	number2("aaaaaaaaaaaaaaaaaaaaaaaaa");

	BigNumber number3 = number1 * number2;

	std::cout << number3.toString() << "\n";

	BigNumber number4 = number3 / number1;

	std::cout << number4.toString() << "\n";
	*/

	BigNumber
		number("d"),  //13
		modulo("11"); //17


					  // 1/13 mod 17 = 4

	BigNumber inverted = inverse(number, modulo);

	std::cout << inverted.toString() << "\n";


	// https://safecurves.cr.yp.to/
	// curve M-383
	// y^2 = x^3+2065150x^2+x 
	// mod 2^383 - 187

	// 383 = 32*12 - 1;

	system("pause");
}
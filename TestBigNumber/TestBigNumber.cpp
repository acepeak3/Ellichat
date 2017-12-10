#include <iostream>
#include "../BigArifmetic/BigNumber.h"
#include "../BigArifmetic/BigArifmetic.h"

int main()
{
	BigNumber 
	//	number("5a54afbc987df513ddf59bc7895ffc626cda"),
		number1("aaaaddd8d7874542fa56aaaff"),
		number2("cccc78dddd");

	//cout << number.toString() << endl;

	BigNumber number3 = number1 + number2;

	cout << number3.toString() << endl;

	system("pause");
}
#include <iostream>
#include "../BigArifmetic/BigNumber.h"
#include "../BigArifmetic/BigArifmetic.h"

int main()
{
	BigNumber
		number1("7"),
		number2("3");


	//	number1("5a54afbc987df513ddf59bc7895ffc626cda"),
	//	number2("a5649865bcdfbc987df513ddf59bc7f5156");

	//	number1("aaaaddd8d78745454654654564dcbbdaaaaddd8d7874545465745454654654564dcbbbbdddcc2fa56aaaf4654564dcbbbbdddcc2fa56aaafcccc78ddddaaaaddd8d78745454654654564dcbbbbdddcc2fa56aaafffaaaaddd8d78745454654654564dcbbbbdddcaaddd8d78745454654654564dcbbbbdddcc2fa56aaafffaaaaddd8d78745454654654564dcbbbbdddcc2fa56aaaffdaaaaddd8d7874545465c2fa56aaaffdaaaaddd8d78745454654654564dcbbbbdddcc2fa56aaafffaaaaddd8d787454546546545"),
	//	number2("4654564dcbbbbdddcc2fa56aaafcccc78ddddaaaadd4654564dcbbbbdddccaaaaddd8d78745454654654564dcbaaddd8d78745454654654564dcbbbbdddcc2fa568ddddaaaaddd8d78745454654654564dcbbbbdddccaaafffaaaaddd8d78745454654654564dcbbbbdddcc2fa56aaaffdaaaaddd8d7874545465bbbdddcc2fa56aaaf4654566aaafffaaaaddd8d78745454654654564dcbbbbdddcc2fa56aaaffdaaaaddd8dbdddcc2fa56aaaffdaaaaddd8d7bdddcc2fa56aaaffdaaaaddd8d77f");

	//cout << number.toString() << endl;

	BigNumber number3 = number1 + number2,
		number4 = number1 - number2,
		number5 = number1 * number2;

	cout << number3.toString() << endl;
	cout << number4.toString() << endl;
	cout << number5.toString() << endl;

	cout << (number1 == number2 ? "yes" : "no") << endl;
	cout << (number1 > number2 ? "yes" : "no") << endl;
	cout << (number1 < number2 ? "yes" : "no") << endl;


	system("pause");
}
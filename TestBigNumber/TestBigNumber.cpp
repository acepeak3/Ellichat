#include <iostream>
#include "../BigArifmetic/BigNumber.h"
#include "../BigArifmetic/BigArifmetic.h"

int main()
{
	BigNumber 
	//	number("5a54afbc987df513ddf59bc7895ffc626cda"),
		number1("aaaaddd8d78745454654654564dcbbbbdddcc2fa56aaaf4654564dcbbbbdddcc2fa56aaafcccc78dddaaaaddd8d78745454654654564dcbbbbdddcc2fa56aaaf4654564dcbbbbdddcc2fa56aaafcccc78ddddaaaaddd8d78745454654654564dcbbbbdddcc2fa56aaafffaaaaddd8d78745454654654564dcbbbbdddcc2fa56aaaffdaaaaddd8d78745454654654564dcbbbbdddcc2fa56aaafffaaaaddd8d78745454654654564dcbbbbdddcc2fa56aaaff"),
		number2("4654564dcbbbbdddcc2fa56aaafcccc78ddddaaaadd4654564dcbbbbdddcc2fa56aaafcccc78ddddaaaaddd8d78745454654654564dcbbbbdddcc2fa56aaaffd8d787454546546545aaaaddd8d78745454654654564dcbbbbdddcc2fa56aaaf4654564dcbbbbdddcc2fa56aaafcccc78ddddaaaaddd8d78745454654654564dcbbbbdddcc2fa56aaafffaaaaddd8d78745454654654564dcbbbbdddcc2fa56aaaff64dcbbbbdddcc2fa56aaaff");

	//cout << number.toString() << endl;

	BigNumber number3 = number1 + number2;

	cout << number3.toString() << endl;

	system("pause");
}
#include <iostream>
#include <exception>
#include <stdexcept>
#include <string>
#include <cctype>
#include <sstream>
#include <limits>

double solve(int a, int b) {
	if (b == 0) {
		throw std::invalid_argument("Can't device by 0");
	}
	else if (a == 0 && b == 0) {
		throw std::invalid_argument("Infinite loop detected");
	}
	else if (a == 0) {
		throw std::invalid_argument("No sollution");
	}
	return double(-b) / a;
}

bool ispalindrome(const std::string& str)
{
	return std::equal(str.begin(), str.end(), str.rbegin());
}

int convert_to_int(const std::string& str)
{
	if (str[0] == '-') {
		std::string str1 = std::string(str.begin() + 1, str.end());
		return -convert_to_int(str1);
	}
	int result = 0;
	for (unsigned i = 0; i < str.size(); ++i)
	{
		if (!isdigit(str[i]))
		{
			std::ostringstream ostr_err;
			ostr_err << "Cannot convert " << str << " to int."
				"The argument contains one or more non-digit characters.";
			throw std::invalid_argument(ostr_err.str());
		}
		if (result != 0 && std::numeric_limits<int>::max() / result <= 10) {
			throw std::invalid_argument("Out of range of integer");
		}
		result *= 10;
		result += str[i] - '0';
	}
	return result;
}

int main() {
	try
	{
		//std::cout << std::numeric_limits<int>::max();
		std::cout << "converting 123: " << convert_to_int("-123") << "\n";
		//std::cout << "converting 12: " << convert_to_int("12") << "\n";
		std::cout << "converting 123123654789: " << convert_to_int("123123654789") << "\n";
	}
	catch (std::invalid_argument const & ex)
	{
		std::cout << "Error while converting number to int:\n" << ex.what();
	}
	/*
	try {
		while (true) {
			int a, b;
			std::string str;
			std::cin >> a >> b;
			std::cout << "Enter String: " ;
			std::cin >> str;
			std::cout << "Devision result of numbers: " << solve(a, b) << std::endl;
			std::cout << "Is string Palindrome? " << (ispalindrome(str) ? "YES" : "NO") << std::endl;

		}

	}
	catch (std::exception const & ex){
		std::cout << "Error while converting number to int: " << ex.what() << std::endl;
	}*/
	system("pause");

}
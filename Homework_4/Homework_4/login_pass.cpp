#include <iostream>
#include <algorithm>
#include <string>

int main() {
	std::string st = "Anna.Karelina/Tramvay";

	std::string::iterator pos = std::find(st.begin(), st.end(), '/');
	std::fill(++pos, st.end(), '*');
	std::cout << st << std::endl;
	
	st = "a/b";

	pos = std::find(st.begin(), st.end(), '/');
	std::fill(++pos, st.end(), '*');
	std::cout << st << std::endl;

	system("pause");
}
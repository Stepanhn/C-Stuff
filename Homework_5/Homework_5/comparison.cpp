#include <iostream>
#include <algorithm>
#include <string>

int main() {
	std::string s1 = "1234123412341234123512345678";
	std::string s2 = "1234123412341234123400000000";
	//make strings equal length by adding 0's from begining
	while (s1.size() != s2.size()) {
		if (s1.size() > s2.size()) {
			s2 = '0' + s2;
		}
		else {
			s1 = '0' + s1;
		}
	}
	//find first missmatch and compare
	auto pair_1 = std::mismatch(s1.begin(), s1.end(), s2.begin());

	if (pair_1.first == s1.end() && pair_1.second== s2.end()) {
		std::cout << "=";
	}
	else  if (*pair_1.first > *pair_1.second) {
		std::cout << ">"; 
	}
	else {
		std::cout << "<"; 
	}
	system("pause");
}
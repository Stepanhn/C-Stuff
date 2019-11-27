#include <iostream>
#include <algorithm>
#include <string>

int main() {
	std::string s[3] = { "BadenBaden","HelloHell", "HelloHello" };
	
	for (std::string sx : s) {
		if (std::equal(sx.begin(), (sx.begin() + sx.size() / 2), sx.begin() + sx.size() / 2)){
			std::cout << sx << ": YES" << std::endl;
		}
		else{
			std::cout << sx << ": NO" << std::endl;
		}
	}
	system("pause");
}

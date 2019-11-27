#include <iostream>
#include <algorithm>
#include <string>
int main() {
	//std::string st = "the quick brown fox jumps over the lazy dog";
	std::string st = "hello world";
	st.erase(std::remove(st.begin(), st.end(), ' '), st.end());
	std::sort(st.begin(), st.end());
	st.erase(std::unique(st.begin(), st.end()), st.end());
	std::cout << st << std::endl;
	system("pause");
}
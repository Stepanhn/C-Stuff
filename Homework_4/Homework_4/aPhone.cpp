#include <iostream>
#include <string>
#include <deque>


class aPhone {
public:
	aPhone(int m) :size_(m), de(m, "<Empty>") {

	}

	void add_number(const std::string& st) {
		std::deque<std::string>::iterator it = std::find(de.begin(), de.end(), st);
		if (it == de.end()) { // theres no such element
			if (size_ == de.size()) {
				de.pop_back();
				de.push_front(st);
			}
			else {
				de.push_front(st);
			}
		}
		else { //there is such element
			for (; it != de.begin(); --it) {
				std::iter_swap(it - 1, it);
			}
		}
	}
	void print() {
		for (int i = 0; i < size_; ++i)
		{
			std::cout << de[i] << " ";
		}
	}


private:
	int size_;
	std::deque<std::string> de;
};

int main() {
	int m, n;
	std::cin >> m >> n;
	aPhone phone(m);
	for (int i = 0; i < n; i++) {
		std::string st;
		std::cin >> st;
		phone.add_number(st);
	}
	phone.print();

	system("pause");

}
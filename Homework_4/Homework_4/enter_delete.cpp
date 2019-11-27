#include <iostream>
#include <vector>

template <class t>
void insert_into_vector(std::vector<t>& v, int pos, const t& elem) {
	v.push_back(elem);

	for (int i = v.size()-1; i!=pos; --i) {
		std::swap(v[i], v[i-1]);
	}
}

template <class T>
void erase_from_vector(std::vector<T>& v, int pos) {
	for (int i = pos; i + 1 != v.size(); i++) {
		std::swap(v[i],v[i + 1]);
	}
	v.pop_back();
}

int main() {
	std::vector<int> v = { 1,2,3,4 };
	insert_into_vector(v, 2, 7);
	std::cout << v.size()<<std::endl;
	for (int i = 0; i < v.size(); ++i) {
		std::cout << v[i];
	}
	std::cout << std::endl;
	erase_from_vector(v, 0);
	std::cout << v.size() << std::endl;
	for (int i = 0; i < v.size(); ++i) {
		std::cout << v[i];
	}
	std::cout << std::endl;

	
	system("pause");
}
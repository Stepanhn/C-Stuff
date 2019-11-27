#include <iostream>
#include <algorithm>
#include <vector>


int main() {
	std::vector<int> v;
	int size;
	std::cout << "Enter size: ";
	std::cin >> size;
	int temp;
	for (int i = 0; i < size; i++) {
		std::cin >> temp;
		v.push_back(temp);
	}
	//std::vector<int> v{ 4, 1, 0, 4, 4 };
	auto it1 = std::max_element(v.begin(), v.end());
	auto it2 = std::max_element(v.rbegin(), v.rend());

	int answer = std::count(it1 + 1, (it2+1).base(), 0);
	std::cout << "Answer is: " << answer << std::endl;
	system("pause");
}

#include <iostream>

bool isPalindrome(char* left, char* right) {
	char* r = right;
	char* l = left;
	for (int i = 0; i < (right - left) / 2; ++i) {
		if (*l!=*(r-1))	{
			return false;
		}
		r--;
		++l;
	}
	return true;
}


int main() {
/*
	char sequence[] = "cdabbadcasd";
	bool full_str = isPalindrome(sequence+2, sequence + 11);
	std::cout << full_str << std::endl;
	bool orig_str = isPalindrome(sequence, sequence + 8);
	std::cout << orig_str << std::endl;
*/

	int x = 10;

	int* k[5];
	k[0] = nullptr;
	k[1] = &x;
	std::cout << *k[1] << std::endl;

	int arr[5] = { 1,2,3,4,5 };
	//arr[0]
	int* ptr = &arr[0];
	int** ptr2 = &ptr;

	std::cout << (*ptr2)[0] << std::endl;

	std::cin.get();
}
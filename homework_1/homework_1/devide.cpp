
#include <iostream>


int devide(int number, int devider, int* ptr = nullptr) {
	if (ptr)
		*ptr = number % devider;
	return number / devider;
}

int main() {

	int a = 0;
	//int* ptr = &a;
	std::cout << "No address given " << devide(20, 3) << "\t" << a << std::endl;

	//Why this doesnt work? It updates variable a but doenst print on same line.
	std::cout << "Address given " << devide(20, 3, &a) << "\t" << a << std::endl;

	// But this does.
	int b = devide(19, 3, &a);
	std::cout << "Address given " << b << "\t" << a << std::endl;


}

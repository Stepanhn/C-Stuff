
#include <iostream>
#include <array>

void getAllPrime(std::array<bool, 1000000>& is_prime) {
	//algorithm
	bool thereIsFlag = 0;
	int iteration = 1;
	is_prime[0] = false;
	is_prime[1] = false;
	for (int i = 2; i < is_prime.size(); i++) {
		if (is_prime[i] != true) {
			is_prime[i] = false;
		}
		iteration = 2;
		while (i*iteration < is_prime.size()) {
			//if element is already marked, continue.
			if (is_prime[i*iteration] == true) {
				iteration++;
				continue;
			} // not  marked element
			else {
				thereIsFlag = 1;
				is_prime[i*iteration] = true;
				iteration++;
			}
		}
		// if all elements are already marked in that range, exit. We're done.
		if (!thereIsFlag) {
			return;
		}
	}



}

//int devide(int number, int devider, int* ptr = nullptr) {
//	if (ptr)
//		*ptr = number % devider;
//	return number / devider;
//}



bool isPalindrome(char* left, char* right) {
	for (int i = 0; i < (right - left) / 2; ++i)
	{
		std::cout << "iteration " << i << std::endl;
		std::cout << *left << " " << *right << std::endl;
		std::cout << left << " " << right << std::endl;

		if (*left != *(right - 1))
			return false;
		right--;
		++left;
	}

	return true;

}
 constexpr int power(int n, int b) {
	 return (b==0)?n:power(n*2,b-1);
}

constexpr int add(int a, int b)
{
	return a + b;
}


int main() {

	const int b[power(2, 2)] = {1,2,3,4};

	for (int i = 0; i < 4; ++i) {
		b[i] = i;
	}
	for (int i = 0; i < 4; ++i) {
		std::cout << b[i] << std::endl;
	}
	std::cout << b;
	int a = 5;
	constexpr int b = a;

	int q1 = add(1, 2);
	//is q1 a constant expression? Why?
	const int q2 = add(q1, 3);
	//is q2 a constant expression? Why?
	const int q3 = add(1, 2);
	//is q3 a constant expression? Why?
	const int q4 = add(q3, q3);
	//is q4 a constant expression? Why?
	constexpr int q5 = add(1, 2);
	//is q5 a constant expression? Why?
	int k[q2];

	//char sequence[] = "cdabbadc";
	//bool vasya = isPalindrome(sequence, sequence + 8);
	//std::cout << vasya << std::endl;
	//
	////find array
	//	std::array<bool, 1000000> results;
	//	getAllPrime(results);
	//	//Start communication with user
	//	int number;
	//	std::cout << "Please enter Number in Range 0 - 1000000" << std::endl;
	//	while (true) {
	//		if (std::cin.fail())
	//		{
	//			std::cout << "Detected" << std::endl;
	//			std::cin.clear();
	//			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	//		}
	//		std::cout << "Enter Number: " ;
	//		std::cin >> number;

	//		if (number > 1000000) {
	//			std::cout << "Please enter number in range: 2-100000" << std::endl;
	//		} else if (number > 0) {
	//			std::cout << "Is Prime? " << (!results[number]?"YES":"NO") << std::endl;
	//		}
	//		else {
	//			std::cout << "Wrong input data. Terminating!" << std::endl;
	//		}
	//	}
	//	
	//int x = 10;
	//int num;
	//std::cin >> num;
	//int ar[num];
	//std::array<int, num> arr2;
	//is_constexpr()
	//	int* arr_of_pointers[5];
	//arr_of_pointers[0] = nullptr;
	//arr_of_pointers[1] = &x;
	//x = 5;
	//std::cout << *arr_of_pointers[1] << std::endl;
	//int arr[5] = { 1,2,3,4,5 };
	//int* ptr = &arr[0];
	//int** ptr_to_array = &ptr;
	//(*ptr_to_array)[0] = 0;
	//std::cout << arr[0] << std::endl;
	//// Pointer to array of pointers to int
	//x = 15;
	//int** ptr3 = arr_of_pointers;
	//std::cout << *ptr3[1] << std::endl;

	//std::cin.get();

	//int a = 0;
	////int* ptr = &a;
	//std::cout << "No address given " << devide(20, 3) << "\t" << a << std::endl;
	//
	////Why this doesnt work? It updates variable a but doenst print on same line.
	//std::cout << "Address given " << devide(20, 3, &a) << "\t" << a << std::endl;
	//
	//// But this does.
	//int b = devide(19, 3, &a);
	//std::cout << "Address given " << b << "\t" << a << std::endl;


}
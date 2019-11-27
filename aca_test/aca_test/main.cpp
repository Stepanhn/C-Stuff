#include <iostream>

int number(int base, int first, int second, char nshan, char nextnshan, char flag) {
	char a;
	while (std::cin >> a) {
		if ((a == '+' || a == '*' || a == '-') && flag == 1){
			if (a == '+') {
				base = first + second;
			}
			else if (a == '-') {
				base = first - second;
			}
			else if (a == '*') {
				base = first * second;
			}
		}
		else 
	}
}
int main() {
	/*
	int a = 121;
	int b = 122;
	int numbers[10] = { 0,0,0,0,0,0,0,0,0,0 };
	int temp = a;
	while (temp > 0) {
		int temp2 = temp % 10;
		//std::cout << temp2 << "eh"<< std::endl;
		numbers[temp2]++;
		temp = temp / 10;
	}
	for (int i = 0; i < 10; i++) {
		std::cout << numbers << std::endl;
	}*/
	int a;
	while (std::cin >> a)
	{
		std::cout << "a" << std::endl;
	}

	
}
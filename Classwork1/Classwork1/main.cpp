/*
input the number of elements of an integer array,
followed by the elements themselves, and output them in reversed order
Sample Input:
4
16 9 -20 5
Sample Output:
5 -20 9 16
*/

#include <iostream>
#include <string>
struct people {
	std::string name;
	int age;

	people(std::string name, int age) 
		:name(name), age(age)
	{}


};
int  max_element_value(int* a, int* b)
{
	int maxval = *a;
	for (int* p = a; p != b; ++p) {
		if (*p > maxval)
		{
			maxval = *p;
		}
	}
	return maxval;
}
int* max_element_pointer(int* a, int* b)
{
	int* max_val_pointer = a;
	
	for (int* p = a; p != b; ++p) {
		if (*p > *max_val_pointer)
		{
			max_val_pointer = p;
			}
	}
	return max_val_pointer;

}
int convert_string_to_int(const std::string& str, bool* ok = nullptr)
{
	int result = 0;
	int count = 1;
	bool isMinus = str[0] == '-';
	int start = 0;
	if (isMinus)
		++start;
	for (int i = start; i < str.size(); ++i) {
		if (str[i] >= '0' && str[i] <= '9') {
			result = result * 10 + int(str[i]) - '0';
		
		}
		else {
			if (str[i] == '-') {
				isMinus = 1;
				break;
			}
			if (ok)
				*ok = false;
			return false;
		}
	}
	if (ok) {
		*ok = true;
	}
	if (isMinus)
		return 0 - result;
	else 
		return result;
}
void copy_arr(int* first, int number, int* dest) {
	for (int i = 0; i < number; ++i)
	{
		dest[i] = first[i];
	}
}
people* get_oldest(people* a, const int count) {
	people* ptr = a;
	int max_age = a[0].age;
	for (int i = 0; i < count; ++i)
	{
		if (a[i].age > max_age) {
			max_age = a[i].age;
			ptr = a + i;
		}
	}
	return ptr;
}
struct llist {

	int number;
	llist* next;

	llist(int n) : number(n),next(nullptr) 
	{	
	}
	llist(int n, llist* next) : number(n), next(next) {}
};
llist* find_element(llist* head, int number) {
	if (head->number == number) {
		return head;
	}
	while (head->next)
		if (head->number == number) {
			return head;
		}
		else
		{
			find_element(head->next, number);
		}
	return false;
}

int main()
{
	/*
	int arr[] = { 1,2,24,4,51,6,75,8,19,210 };
	//std::cout << max_element_value(arr, arr + 10) << std::endl;
	//std::cout << max_element_value(arr, arr + 5)<< std::endl;
	//std::cout << max_element_pointer(arr,arr+10) - arr << std::endl;

	bool success = false;
	int res = convert_string_to_int("-27", &success);
	if (success)
		std::cout << res << std::endl;
	else
		std::cout << "ERROR: Cant convert to Int!" << std::endl;


	copy_arr(arr, 5, arr + 5);
	for (int i = 0; i < 10; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	std::cin.get();


	people a("Stepan", 22);
	people pep[4] = { {"Stepan",22 }, {"Hayk",53}, {"Anna",15}, {"Ashot",30} };
	people* person = get_oldest(pep, 4);
	std::cout << "Max age is: " << person->name << std::endl;
*/

	std::cin.get();
	llist a[4] = { 5,{6,&a[0]},{7, &a[1] }, {8,&a[2]} };
	for (int i = 0; i < 4; ++i)
	{
		std::cout << a[i].number << std::endl;
	}


}
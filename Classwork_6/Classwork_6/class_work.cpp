#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

struct Date {
	int m;
	int y;
	int d;
public:
	Date(int a = 0, int b = 0, int c = 0) :m(a), y(b), d(c) {}

};

class person {

private:
	std::string name;
	std::string s_name;
	Date birth;

public:
	person(std::string name, std::string s_name, Date b) : name(name), s_name(s_name), birth(b) {}

	Date get_date() const {
		return birth;
	}
	std::string get_s_name() const {
		return s_name;
	}
	std::string get_name() const {
		return name;
	}
};



bool operator!=(const Date& d1, const Date& d2) {
	return !(d1.d == d2.d && d1.m == d2.m && d1.y == d1.y);
}

bool is_earlier(const Date& d1, const Date& d2) {
	if (d1.y != d2.y) 
		return d1.y < d2.y;
	if (d1.m != d2.m) 
		return d1.m < d2.m;
	return d1.d<d2.d;
}

bool condition(const person& p1, const person& p2) {
	if (p1.get_date()!= p2.get_date()) {
		return is_earlier(p1.get_date(), p2.get_date());
	}
	if (p1.get_s_name() != p2.get_s_name()) {
		return p1.get_s_name() < p2.get_s_name();
	}
	return p1.get_name() < p2.get_name();
}
std::istream& operator>>(std::istream& in, Date& date)
{
	int a, b, c;
	char c1, c2;
	in >> a >>c1>> b >>c2>> c;
	date.d = a;
	date.m = b;
	date.y = c;
	return in;
}

int main() {
	std::vector<person> v;
	int n;
	std::cin >> n;
	std::string name;
	std::string s_name;
	Date date;
	for (int i = 0; i < n; i++) {
		std::cin >> name >> s_name >> date ;
		v.push_back(person(name, s_name, date));
	}

	std::sort(v.begin(), v.end(), condition);
	for (int i = 0; i < n; i++) {
		std::cout << v[i].get_name() << " " <<v[i].get_s_name() << std::endl;
	}

	system("pause");
}

//1st task
//
//bool isPrime(int a) {
//	for (int i = 2; i < a/2; ++i) {
//		if (a%i == 0) {
//			return false;
//		}
//	}
//	return true;
//}
//bool isIt(int a) {
//	return a >= 10 && a < 100;
//}
//bool isOdd(int a) {
//	return a % 2 != 0;
//}
//
//int main() {
//	int n;
//	std::vector<int> v;
//	std::cin >> n;
//	int temp;
//	for (int i = 0; i < n; ++i) {
//		std::cin >> temp;
//		v.push_back(temp);
//	}
//	v.erase(std::remove_if(v.begin(), v.end(), isPrime),v.end());
//	for (int i = 0; i < v.size(); ++i) {
//		std::cout << v[i]<< " ";
//	}
//	auto found = std::find_if(v.begin(), v.end(), isIt);
//	if (found != v.end()) {
//		std::cout << *found << std::endl;
//	}
//	else {
//		std::cout << "theres no double digit in numbers" << std::endl;
//	}
//	std::cout <<std::count_if(std::max_element(v.begin(),v.end()), v.end(), isOdd)<<std::endl; 
//	system("pause");
//}
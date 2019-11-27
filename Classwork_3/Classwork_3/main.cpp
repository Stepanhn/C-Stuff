#include <iostream>
#include <iomanip>
#include <vector>
#include <windows.h>
#include <algorithm>

class Time {
private:
	int h;
	int m;
	int s;

public:
	Time() :Time(0, 0, 0) {}
	Time(int a, int b, int c = 0) :h(a), m(b), s(c) {
		if (a > 23 || a < 0) { a = 0; }
		if (b > 59 || b < 0) { b = 0; }
		if (c > 59 || c < 0) { c = 0; }
	}


	int get_hour() { return h; }
	
	void print(std::ostream& out = std::cout) const {
		out << std::setfill('0');
		out << std::setw(2) << h << ":" << std::setw(2) << m << ":" << std::setw(2) << s << std::endl;
	}

	void normalize(int& a, int& b, int& c) {
		if (a > 23) { a -= 23; }
		else if (a < 0) { a = 0; }
		if (b > 59 || b < 0) { b -= 59; }
		else if (b < 0) { b = 0; }
		if (c > 59 || c < 0) { c -= 59; }
		else if (c < 0) { c = 0; }
	}

	void AddSeconds(int seconds_added)
	{
		int all_seconds = h * 3600 + m * 60 + s + seconds_added;
		if (all_seconds < 0) { //we will use this for substract with - value
			all_seconds = 24 * 60 * 60 + all_seconds;
		}
		int h_added = all_seconds / 3600;
		int m_added = (all_seconds - h_added * 3600) / 60;
		int s_added = all_seconds - h_added * 3600 - m_added * 60;

		normalize(h_added, m_added, s_added);
		h = h_added;
		m = m_added;
		s = s_added;

	}
	void Substract(int seconds_removed)
	{
		AddSeconds(-seconds_removed);
	}
	bool equal(const Time& timesample) {
		return timesample.m == this->m && timesample.h == this->h && timesample.s == this->s;
	}

};

std::string GetTimeOfDay(Time& timesample) {
	int hour = timesample.get_hour();
	if (hour > 0 && hour <= 7 || hour >= 22) {
		return "Night";
	}
	else if (hour > 7 && hour < 11) {
		return "Morning";
	}
	else if (hour >=11 && hour < 18) {
		return "Afternoon";
	}
	else if (hour >= 18 && hour <22) {
		return "Evening";
	}
}



template <class T>
int uniqueCount(std::vector<T> vec)
{
	int count = 1;
	std::sort(vec.begin(),vec.end());
	for (int i = 0; i+1 < vec.size(); ++i)
	{
		if (vec[i] != vec[i + 1]) {
			++count;
		}
	}
	return count;

}


template <class T>
class PriorityQueue {
private:
	std::vector<T> vec;

	int Min_idx() const {
		int min_ind = 0;
		for (int i = 1; i < vec.size(); ++i)
			if (vec[i] < vec[min_ind]) {
				min_ind = i;
			}
		return min_ind;
	}	

public:


	void push(const T& element) {
		vec.push_back(element);
		while ()
	}
	int size() const {
		return vec.size();
	}

	T Min() const {
		return vec[Min_idx()];
	}


	void Pop() {
		std::swap(vec[Min_idx()], vec.back());
		vec.pop_back();
	}
	void clear() {
		vec.clear();
	}
	bool empty() const {
		return vec.empty();
	}

};


int main() {
/*
	Time time;
	Time time2(2, 4, 10);
	Time time3(20, 40);
	std::cout << "Time before add: ";
	time2.print();
	time2.AddSeconds(5000);
	std::cout << "Time After add: ";
	time2.print();

	std::cout << "Time before substract: ";

	time3.print();
	time3.Substract(70);
	std::cout << "Time After substract: ";
	time3.print();

	std::cout << "checking if equal Time 1 ";
	time2.print();
	std::cout << "Time 2 ";
	time3.print();
	std::cout << "Result is: " << time3.equal(time2) << std::endl;
	
	
	std::cout << "Time of day with hour ";
	time3.print();
	std::cout << "is " << GetTimeOfDay(time3) <<std::endl;

	int sleep_for = 10;
	std::cout << "starting Time: ";
	time3.print();

	while (sleep_for) {
		Sleep(1000);
		time3.Substract(1);
		time3.print();
		sleep_for--;
	}
*/
	/*std::vector<int> a = {1,2,1,3,1,4};
	
	std::cout << uniqueCount(a)<<std::endl;

	std::vector<char> b = { 'a','a', 'a', 'e', 'a', 'k', 'a', 'd', 'c', 'b' };
	std::cout << uniqueCount(b) << std::endl;
	*/
	PriorityQueue<int> q;
	q.push(3);
	q.push(4);
	q.push(5);
	std::cout << q.Min(); //prints 3;
	q.Pop();
	std::cout << q.Min(); //prints 3;
	q.Pop();
	std::cout << q.Min(); //prints 4;
	if (q.empty()) //false
	{
		std::cout << "will not be printed";
	}

	q.clear(); //or q.pop()

	if (q.empty()) //true
	{
		std::cout << "will be printed";
	}
	}
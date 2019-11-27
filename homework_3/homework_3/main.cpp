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
	else if (hour >= 11 && hour < 18) {
		return "Afternoon";
	}
	else if (hour >= 18 && hour < 22) {
		return "Evening";
	}
}



template <class T>
int uniqueCount(std::vector<T> vec)
{
	int count = 1;
	std::sort(vec.begin(), vec.end());
	for (int i = 0; i + 1 < vec.size(); ++i)
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

public:
	void print() const {
		for (int i = 0; i < vec.size(); ++i) {
			std::cout << vec[i] << " " ;
		}
		std::cout << std::endl;
	}

	void push(const T& element) {
		vec.push_back(element);
		int cur_idx = vec.size() - 1;
		while (vec[(cur_idx - 1) / 2] > vec[cur_idx]) {
			std::swap(vec[(cur_idx - 1) / 2], vec[cur_idx]);
			cur_idx = (cur_idx - 1) / 2;
		}
	}

	int size() const {
		return vec.size();
	}

	T Min() const {
		return vec[0];
	}


	void Pop() {
		std::swap(vec[0], vec.back());
		vec.pop_back();
		//last element deleted, checking if isheap
		int cur_idx = 0;
		bool has_child = 1;
		while ((has_child ) && (vec[cur_idx] > vec[2 * cur_idx + 1] || vec[cur_idx] > vec[2 * cur_idx + 2])) {
			
			if (vec[2 * cur_idx + 1] < vec[2 * cur_idx + 2]) {  //left side, this must swap with min of children
				std::swap(vec[cur_idx], vec[2 * cur_idx + 1]);
				cur_idx = 2 * cur_idx + 1;
			}
			else { //right side swap
				std::swap(vec[cur_idx], vec[2 * cur_idx + 2]);
				cur_idx = 2 * cur_idx + 2;
			}
			has_child = (2 * cur_idx + 1 < vec.size() && 2 * cur_idx + 2 < vec.size());
		}

	}
	void clear() {
		vec.clear();
	}
	bool empty() const {
		return vec.empty();
	}

};

template <class T, class U = T>
class AverageCounter {
private:
	std::vector<T> vec;
	U sum;

public:
	void reset() {
		vec.clear();
		sum = 0;
	}

	void add(const T& element) {
		vec.push_back(element);
		sum += element;
	}

	U get() const {
		if (vec.empty()) {
			return -1;
		}
		else {
			return sum / vec.size();
		}
	}

};

int main() {
	AverageCounter<int> avg1; //same as AverageCounter<int, int>
	avg1.add(2);
	avg1.add(4);
	std::cout << avg1.get(); //prints 3
	avg1.add(8);
	std::cout << avg1.get(); //prints 4, because average is of type
	avg1.reset();
	std::cout << avg1.get(); //undefined behavior, must add number first
	avg1.add(5);
	std::cout << avg1.get(); //prints 5;
	AverageCounter<int, double> avg2;
	avg2.add(3);
	avg2.add(4);
	std::cout << avg2.get(); //prints 3.5
}
	//PriorityQueue<int> q;
	//q.push(1);
	//q.push(3);
	//q.push(6);
	//q.push(5);
	//q.print();
	//q.push(2);
	//q.print();
	//q.push(10);
	//q.print();
	//q.Pop();
	//q.print();
	//q.push(1);
	//q.print();
	//q.push(2);
	//q.print();
	//q.Pop();
	//q.print();
	
//}
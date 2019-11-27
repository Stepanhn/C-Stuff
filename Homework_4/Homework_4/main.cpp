#include <iostream>
#include <deque>
#include <math.h>
class sequence {
public:

	void add(int a) {
		right.push_back(a);
		fix();
	}

	void take() {
		if (left.empty()){
			return;
		}
		left.pop_front();
		fix();
	}

	void swap() {
		std::swap(left, right); 
		fix();
	}	

	void print() {
		std::deque<int>::iterator it = left.begin();
		for (; it != left.end(); ++it) {
			std::cout << *it;
		}
		it = right.begin();
		for (; it != right.end(); ++it) {
			std::cout << *it;
		}
		std::cout << std::endl;
	}

private:
	
	void fix() {
		if (abs(int(right.size()) - int(left.size())) > 1 || left.size()>right.size()) {
			if (right.size() > left.size()) {
				int val = right.front();
				right.pop_front();
				left.push_back(val);
			}
			else {
				int val = left.back();
				left.pop_back();
				right.push_front(val);
			}
		}

	}

private:
	std::deque<int> left;
	std::deque<int> right;

};

int main(){
	sequence a;
	a.add(5);
	a.add(6);
	a.add(7);
	a.add(1);
	a.add(2);
	a.print();
	a.take();
	a.print();
	a.add(9);
	a.add(6);
	a.print();
	a.swap();
	a.print();

	system("pause");
}
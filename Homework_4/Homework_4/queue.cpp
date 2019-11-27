#include <iostream>
#include <deque>

template <class T>
class queue {

public:
	queue() {
	}
	queue() = default;

	void push(const T& t) {
		q.push_back(t);
	}

	T front() const {
		return q.front();
	}

	void pop() {
		q.erase(q.begin());
	}
	bool empty() const {
		return q.empty();
	}

private:
	std::deque<T> q;
};

int main() {
	queue<int> q;
	q.push(4);
	q.push(7);
	q.push(1);
	std::cout << q.front(); // 4
	q.pop();
	std::cout << q.front(); // 7
	system("pause");
}
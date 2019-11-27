
#include <iostream>

struct point {
	int x;
	int y;


	point(int a = 0, int b = 0) : x(a), y(b) {}
};

struct rectangle {

	point left_up;
	point right_dwn;

	rectangle() :left_up(0, 0), right_dwn(0,0)
	{
	}

	rectangle(point a, point b) {
		left_up = a;
		right_dwn = b;
	}
	rectangle(const point& a, int size_x, int size_y) {
		left_up = a;
		right_dwn = point(a.x + size_x, a.y + size_y);
	}

	void reset(const point& a, const point& b) {
		left_up = a;
		right_dwn = b;
	}
	void reset(const point& a, int size_x, int size_y) {
		left_up = a;
		right_dwn = point(a.x + size_x, a.y + size_y);
	}


	int getArea() const {
		return abs((right_dwn.x - left_up.x) * (left_up.y - right_dwn.y));
	}

	int getPerim() const {
		return (abs(right_dwn.x - left_up.x) + abs(left_up.y - right_dwn.y))*2;
	}

	void stretch(int factor) {
		right_dwn.x *= factor;
		right_dwn.y *= factor;
	}

	void move(int x, int y) {
		left_up.x += x;
		left_up.y += y;
		right_dwn.x += x;
		right_dwn.y += y;
	}

	bool contains(const point& a) const {
		return (left_up.x <= a.x && right_dwn.x > a.x && left_up.y >= a.y && right_dwn.y < a.y);
	}

	bool contains(const rectangle& rec) const {
		return (contains(rec.left_up) && contains(rec.right_dwn));
	}
};

void MakeNull(const int*& a) {
	a = nullptr;
}
void MakeNull_1(int*& a) {
	a = nullptr;
}

void print(const rectangle& a)  {
	std::cout << "(" << a.left_up.x << "," << a.left_up.y << ")" << "(" << a.right_dwn.x << "," << a.right_dwn.y << ")"<<std::endl;
}

void print(const point& a) {
	std::cout << "(" << a.x << "," << a.y << ")" << std::endl;
}

int main() {
	point a(2, 7);
	point b(3, 6);
	point c(5, 4);
	point d(6, 3);

	rectangle rec1(a, d);
	print(rec1);
	std::cout << "perimeter and area below" << std::endl;
	std::cout << rec1.getPerim() << std::endl;
	std::cout << rec1.getArea() <<std::endl; 
	print(rec1);
	std::cout << "Strech rectangle by 2" << std::endl;
	rec1.stretch(2);
	print(rec1);
	std::cout << "Moving this rectangle by 2,3" << std::endl;
	rec1.move(2, 3);
	print(rec1);
	
	std::cout << "Rectangle containts point: ";
	print(b);
	std::cout << rec1.contains(b) <<std::endl;
	rec1.reset(a,d);
	rectangle rec2;
	rec2.reset(b, c);
	std::cout << "Rectangle contains other? " << std::endl;
	std::cout << "Rec1: ";
	print(rec1);
	std::cout << "Rec2: ";
	print(rec2);
	std::cout << rec1.contains(rec2)<<std::endl;
	std::cin.get();
}

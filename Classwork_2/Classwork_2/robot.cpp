#include <iostream>

struct robot {

	int x;
	int y;
	char side;
	int life;

	robot() :x(0), y(0), side('X'), life(0) {}
	void init() {
		x = 5;
		y = 5;
		side = 'u';
		life = 100;
	}

	void move() {
		if (side == 'u')
			y += 1;
		else if (side == 'r')
			x += 1;
		else if (side == 'l')
			x -= 1;
		else if (side == 'd')
			y -= 1;
	}

	void turnLeft() {
		if (side == 'u')
			side = 'l';
		else if (side == 'r')
			side = 'u';
		else if (side == 'l')
			side = 'd';
		else if (side == 'd')
			side = 'r';
	}
	void turnRight() {
		if (side == 'u')
			side = 'r';
		else if (side == 'r')
			side = 'd';
		else if (side == 'l')
			side = 'u';
		else if (side == 'd')
			side = 'l';
	}
	void RoundAbout() {
		if (side == 'u')
			side = 'd';
		else if (side == 'r')
			side = 'l';
		else if (side == 'l')
			side = 'r';
		else if (side == 'd')
			side = 'u';
	}

	void ReportPossition() const {
		std::cout << x << " " << y << " side: " << side << std::endl;
	}

	void TakeDamage(int damage) {
		life -= damage;
	}

	bool isAlive()const {
		return life > 0;
	}
};


int main() {
	robot John;
	std::cout << "Init Robot John" << std::endl;
	John.init();
	John.ReportPossition();
	std::cout << "Move John" << std::endl;
	John.move();
	John.ReportPossition();
	std::cout << "Turn John left" << std::endl;
	John.turnLeft();
	John.ReportPossition();
	std::cout << "Turn John Right" << std::endl;
	John.turnRight();
	John.ReportPossition();
	std::cout << "Turn John Around" << std::endl;
	John.RoundAbout();
	John.ReportPossition();
	std::cout << "John's health is: " << John.life << std::endl;
	std::cout << "is John alive? " << John.isAlive() << std::endl;
	std::cout << "John's Takes 110 damage" << std::endl;
	John.TakeDamage(110);
	std::cout << "is John alive? " << John.isAlive();
	std::cin.get();
}
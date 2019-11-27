
#include <iostream>
#include <chrono>


struct tanks {
	int m_health;
	int health;
	int attack;
	double defence;

	tanks(int health = 0, int attack = 0, int defence = 0)
		: m_health(health), health(health), attack(attack), defence(defence)
	{ };

	void Input(int i) {
		std::cout << "Please enter number " << i << " Tank's Charactaristics: health attack defence ";
		while (!(std::cin >> health >> attack >> defence)) {
			std::cin.clear();
			std::cin.ignore(10, '\n');
			std::cout << "Please enter number " << i << " Tank's Charactaristics: health attack defence ";
		}
		m_health = health;
	}

	bool verify() const {
		return !(defence > 1 || defence < 0 || health <= 0 || attack <= 0);
	}

	bool Hit(tanks& defender) const  {
		defender.health -= (this->attack * (this->m_health / this->health))*(1 - defender.defence);
		return defender.health <= 0;
	}
};

int main() {

	auto start = std::chrono::high_resolution_clock::now();

	std::cout << "Welcome to Tank battle." << std::endl;
	tanks t1;
	do { t1.Input(1); } while (!t1.verify());
	tanks t2;
	do { t2.Input(2); } while (!t2.verify());
	auto finish = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = finish - start;

	int turn;
	bool dead = 0;
	while (!dead)
	{
		std::cout << "Enter the number of attacking tank <1 or 2>: ";
		std::cin >> turn;
		if (turn == 1) {
			dead = t1.Hit(t2);
		}
		else if (turn == 2) {
			dead = t2.Hit(t1);
		}
		else {
			std::cout << "Error! " << std::endl;
			break;
		}
		if (!dead) { //just cosmetic change to match our sample from Homework screenshots.
			std::cout << "Tank1 health: " << t1.health << std::endl;
			std::cout << "Tank2 health: " << t2.health << std::endl;
		}
	}
	if (t1.health <= 0) {
		std::cout << "Tank1 is dead!" << std::endl;
	}
	else if (t2.health <= 0) {
		std::cout << "Tank2 is dead!" << std::endl;
	}
	
	system("pause");
}
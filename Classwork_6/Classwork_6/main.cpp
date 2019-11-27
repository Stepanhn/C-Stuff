#include <iostream>
#include <ostream>
#include <istream>
#include <string>

class Fraction {
private:
	int a_;
	int b_;

public:
	Fraction(const Fraction& fr1) {
		this->a_ = fr1.get_up();
		this->b_ = fr1.get_low();
	}
	Fraction(int a = 0, int b = 1) :a_(a), b_(b) { 
		std::cout << a << b << " Consturctor called"<<std::endl;
		normalize(); 
	}
	Fraction invers() const
	{
		return Fraction(b_, a_);
	}
	std::string to_point_str() const {
		return std::string(a_ + "/" + b_);
	}
	Fraction& operator+=(const Fraction& fr1) {
		a_ = this->a_*fr1.get_low() + this->b_*fr1.get_up();
		b_ = this->b_*fr1.get_low();
		return *this;
	}
	Fraction operator-() {
		std::cout << " HELLO " << std::endl;
		std::cout << -this->a_ << " " << this->b_ <<std::endl ;
		return Fraction(-this->a_, this->b_);
	}

	Fraction& operator*=(const Fraction& fr1) {
		a_ *= fr1.get_up();
		b_ *= fr1.get_low();
		return *this;
	}
	Fraction& operator/=(const Fraction& fr1) {
		*this *= fr1;
		return *this;
	}
	explicit operator double() {
		return 1 * a_ / b_;
	}
	explicit operator bool() {
		return (a_ == 0);
	}
	int get_up() const { return a_; }
	int get_low() const { return b_; }

	void print() {
		std::cout << this->a_;
		std::cout << this->b_;
		std::cout << std::endl;
	}
private:
	void normalize() {
		int g = gcd(a_, b_);
		a_ /= g;
		b_ /= g;
	}
	int gcd(int a, int b) {
		return (b == 0) ? a : gcd(b, a%b);
	}
};
bool operator<(const Fraction& fr1, const Fraction& fr2) {
	return  fr2.get_low()*fr1.get_up() < fr1.get_low()*fr2.get_up();
}
//
//bool operator>=(const Fraction& fr1, const Fraction& fr2) {
//	return !(fr1 < fr2);
//}
//bool operator<=(const Fraction& fr1, const Fraction& fr2) {
//	return !(fr1 > fr2);
//}
bool operator>(const Fraction& fr1, const Fraction& fr2) {
	return  fr2.get_low()*fr1.get_up() > fr1.get_low()*fr2.get_up();
}
bool operator==(const Fraction& fr1, const Fraction& fr2) {
	return ((fr1.get_low() == fr2.get_low()) && fr1.get_up() == fr2.get_up());
}
Fraction operator+(const Fraction& fr1, const Fraction& fr2)
{
	return Fraction(fr1.get_up()*fr2.get_low() + fr1.get_low()*fr2.get_up(), fr1.get_low()*fr2.get_low());
}
//Fraction operator-(const Fraction& fr1, const Fraction& fr2) {
//	return fr1 + (-fr2);
//}
//Fraction operator+(const Fraction& fr1)
//{
//	return fr1;
//}
//Fraction operator*(const Fraction& fr1, const Fraction& fr2)
//{
//	return Fraction(fr1.get_up()*fr2.get_up(), fr1.get_low()*fr2.get_low());
//}
//Fraction operator/(const Fraction& fr1, const Fraction& fr2) {
//	return fr1 * fr2.invers();
//}
std::ostream& operator<<(std::ostream& out, const Fraction& fr) {
	out << fr.get_up() << " " << fr.get_low() << std::endl;
	return out;
}
std::istream& operator>>(std::istream& in, Fraction& fr) {
	int a, b = 1;
	char c;
	in >> a;

	in >> c;

	in >> b;
	fr = Fraction(a, b);
	return in;
}

int main() {
	//Fraction fr1;
	Fraction fr2(1, 2);
	//std::cin >> fr1;
	Fraction fr3 = -fr2;
	fr2.print();
	fr3.print();
	std::cout << "Bla bla" << std::endl;
	std::cout << fr3.get_low() << " " << fr3.get_up()<<std::endl;
	/*std::cout << (fr1 > fr2);
	std::cout << -fr2;
	*/
	system("pause");
}


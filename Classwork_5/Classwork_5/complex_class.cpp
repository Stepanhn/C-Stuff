#include <iostream>

class complex {
public:
	complex(double x =0.0, double y = 0.0): re_(x),im_(y) {
		
	}
	
	double re() const {
		return re_;
	}
	double im() const {
		return im_;
	}
	void s_re(const double a) {
		re_ = a;
	}
	void s_im(const double a) {
		im_ = a;
	}

	complex& operator+=(const complex& c1);

	complex operator- (const complex& c1);
	// 6 unary+, member
	complex operator+ () const {
		return *this;
	}
	//8 comparison
	bool operator<(const complex& c1) const {
		return this->im_ < c1.im() && this->re_ < c1.re();
	}
	bool operator>(const complex& c1) const {
		return !(*this < c1);
	}
	bool operator==(const complex& c1) const {
		return !(*this < c1) && !(*this > c1);
	}
	bool operator<=(const complex& c1) const {
		return !(*this > c1);
	}
	bool operator>=(const complex& c1) const {
		return !(*this < c1);
	}
	//end of 8
	//9) mebmer *=
	complex& operator*=(const complex& c1);

private:
	double re_;
	double im_;
};

//9) member *=
complex& complex::operator*=(const complex& c1) {
	this->im_=(this->im_*c1.im());
	this->re_ = (this->re_*c1.re());
	return *this;
}
//10) nonmember *
complex operator*(const complex& c1, const complex c2) {
	complex temp = c1;
	temp *= c2;
	return temp;
}
//11)
complex operator/(const complex& c1, double x) {
	complex temp(c1.re()/x, c1.im()/x);
	return temp;
}

complex operator/(const complex& c1, const complex c2) {
	complex temp(c2.re(),-c2.im());
	temp = (c1*temp) / (c2.re()*c2.re() - c2.im()*c2.im());
	return temp;
}

complex operator/=(complex& c1, const complex& c2) {
	c1 = c1 / c2;
	return c1;
}

//additional ++c1 and c1++
complex& operator++(complex& c1) {
	c1.s_re(c1.re() + 1);
	return c1;
}

complex operator++(complex& c1,int) {
	complex c2 = c1;
	++c1;
	return c2;
}


//12) streams
std::ostream& operator<<(std::ostream& out, const complex& c1) {
	out << c1.re() << " + " << c1.im() << "i";
	return out;
}
std::istream& operator>>(std::istream& in,  complex& c1) {
	double x, y;
	in >>x>>y;
	c1.s_im(y);
	c1.s_re(x);
	return in;
}

//1) binary +, non-member
complex operator+(const  complex& c1, const  complex& c2) {
	return complex(c1.re() + c2.re(), c1.im() + c2.im());
}
//2) binary +=, member
complex& complex::operator+=(const complex& c1) {
	*this = *this + c1;	
	return *this;
}
//3) binary -=, nonmember
complex& operator-=(complex &c1, const complex& c2) {
	c1.s_re(c1.re() - c2.re());
	c1.s_im(c1.im() - c2.im());
	return c1;
}

//4) binary -, member
complex complex::operator- (const complex& c1){
	return *this -= c1;
}

//5) unary -, nonmember
complex operator-(const complex& c1) {
	return complex(-c1.re(), -c1.im() );
}

int main() {
	complex c1(2,6);
	complex c2(3, 5);
	//c1 += c2 ;
	std::cout<< c2 - c1 <<std::endl;
	std::cout<< c2 / c1 << std::endl;
	std::cout<< c2 * c1 << std::endl;
    c1++;
	++c2;
	
	std::cout << c1 << "\n" << c2 << "\n";
	if (c1 < c2)
	{
		std::cout << "c1 > c2";
	}
	system("pause");
}
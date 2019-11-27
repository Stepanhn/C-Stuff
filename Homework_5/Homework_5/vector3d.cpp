#include <iostream>
#include <vector>
#include <ostream>
#include <istream>
class Vector3D {
public:
	//0
	Vector3D(double a=0.0,double b=0.0, double c = 0.0):vx_(a),vy_(b),vz_(c) {}

	double get_vx()const {
		return vx_;
	}
	double get_vy()const {
		return vy_;
	}
	double get_vz()const {
		return vz_;
	}
	void set_vx(double a) {
		vx_ = a;
	}
	void set_vy(double a) {
		vy_ = a;
	}
	void set_vz(double a) {
		vz_ = a;
	}

private:
	double vx_;
	double vy_;
	double vz_;


};

//1 operator>>
std::istream& operator>>(std::istream& in, Vector3D& vec) {
	double a, b, c;
	in >> a >> b >> c;
	vec.set_vx(a);
	vec.set_vy(b);
	vec.set_vz(c);
	return in;
}

//2 operator <<
std::ostream& operator<<(std::ostream& out, const Vector3D& vec) {
	out << "[" << vec.get_vx() << "," <<vec.get_vy() << ","<< vec.get_vz() << "]" ;
	return out;
}

//3 + and - operators
Vector3D operator+(const Vector3D& vec1, const Vector3D& vec2) {
	return Vector3D(vec1.get_vx() + vec2.get_vx(), vec1.get_vy() + vec2.get_vy(), vec1.get_vz() + vec2.get_vz());
}
Vector3D operator-(const Vector3D& vec1, const Vector3D& vec2) {
	return Vector3D(vec1.get_vx() - vec2.get_vx(), vec1.get_vy() - vec2.get_vy(), vec1.get_vz() - vec2.get_vz());
}

//4 unary + and -
Vector3D operator+(const Vector3D& vec1) {
	return vec1;
}
Vector3D& operator+=(Vector3D& vec1, const Vector3D& vec2) {
	vec1.set_vx(vec1.get_vx() + vec2.get_vx());
	vec1.set_vy(vec1.get_vy() + vec2.get_vy());
	vec1.set_vz(vec1.get_vz() + vec2.get_vz());
	return vec1;
}

Vector3D operator-(const Vector3D& vec1) {
	return Vector3D(-vec1.get_vx() , -vec1.get_vy() , -vec1.get_vz());
}
//5 operator == and !=
bool operator==(const Vector3D& vec1, const Vector3D& vec2) {
	return ((vec1.get_vx() == vec2.get_vx()) && (vec1.get_vy() == vec2.get_vy()) && (vec1.get_vz() == vec2.get_vz()));
}
bool operator!=(const Vector3D& vec1, const Vector3D& vec2) {
	return !(vec1 == vec2);
}
//6 operator* for vector*vector
Vector3D operator*(const Vector3D& vec1, const Vector3D& vec2) {
	return Vector3D(vec1.get_vy()*vec2.get_vz() - vec1.get_vz()*vec2.get_vy(), vec1.get_vz()*vec2.get_vx() - vec1.get_vx()*vec2.get_vz(), vec1.get_vx()*vec2.get_vy() - vec1.get_vy()*vec2.get_vx());
}
//7 operator^ for skalyar
double operator^(const Vector3D& vec1, const Vector3D& vec2) {
	return (vec1.get_vx()*vec2.get_vx()) + (vec1.get_vy()* vec2.get_vy()) + (vec1.get_vz()*vec2.get_vz());
}
//8 operator * for number devision
Vector3D operator*(Vector3D& vec1, double number) {
	return Vector3D(vec1.get_vx()*number, vec1.get_vy()*number, vec1.get_vz()*number);
}
//9 operator /
Vector3D operator/(Vector3D& vec1, double number) {
	return Vector3D(vec1.get_vx()/number, vec1.get_vy()/number, vec1.get_vz()/number);
}

void test() {
	Vector3D vec1(1, 2.5, 3);
	Vector3D vec2;
	std::cout << "Enter Vector3D element: ";
	std::cin >> vec2;
	std::cout << "Entered Vector3D elment is: " << vec2 <<std::endl;
	std::cout << "operator + and operator - for these Vector3D's " << vec1 << " " << vec2 << std::endl;
	std::cout << "operator +: " << vec1 + vec2 <<std::endl;
	std::cout << "operator -: " << vec1 - vec2 <<std::endl;
	std::cout << "Unary + for Vecotr3d " << vec1 << " is " << +vec1 << std::endl; ;
	std::cout << "Unary -for Vecotr3d " << vec1 << " is " << -vec1 << std::endl;
	std::cout << "operator==: Are they equal? " << ((vec1 == vec2) ? "Yes" : "No") <<std::endl;
	std::cout << "operator!=: Are they different? " << ((vec1 != vec2) ? "Yes" : "No")<<std::endl;
	std::cout << "Vectors and operator * for them (Vector* Vector)" << std::endl;
	std::cout << vec1 << " " << vec2 << " Result: "<< vec1 * vec2 << std::endl;
	std::cout << "Vectors and operator ^ " << std::endl;
	std::cout << vec1 << " " << vec2 << " Result: " << (vec1^vec2) <<std::endl;
	std::cout << "Vectors and operator * for them (Vector * int)" << std::endl;
	std::cout << vec1 << " Multiplied by number 3 Result:" << vec1 * 3 << std::endl;
	std::cout << "Vectors and operator / for them" << std::endl;
	std::cout << vec1 << " Devided y number 3 Result: "  << (vec1/3) << std::endl;


}
// x=x0+ v0t
int main() {
	double m;
	//test();
	std::cout << "Enter weight of object: ";
	std::cin >> m;
	std::cout << "Enter start location: ";
	Vector3D startPoint;
	std::cin >> startPoint;
	std::cout << "Enter speed Vector: ";
	Vector3D speed;
	std::cin >> speed;
	std::cout << "Enter Force Count: ";
	int Fcount;
	std::cin >> Fcount;
	Vector3D fullForce;
	std::cout << "Enter Forces" <<std::endl;

	// holding sum of forces in one Vector3D
	for (int i = 0; i < Fcount; i++) {
		Vector3D temp;
		std::cin >> temp;
		fullForce += temp;
	}
	std::cout << "Enter Time: ";
	int time;
	std::cin >> time;
	// We have all the data inserted

	// Create new vector3D with all results
	Vector3D endRes(startPoint.get_vx() + speed.get_vx()*time + fullForce.get_vx()*time*time / m / 2, startPoint.get_vy() + speed.get_vy()*time + fullForce.get_vy()*time*time / m / 2, startPoint.get_vz() + speed.get_vz()*time + fullForce.get_vz()*time*time / m / 2);
	/* endRes is constructed with this X,Y,Z. Sample below.
	double X = startPoint.get_vx() + speed.get_vx()*time + fullForce.get_vx()*time*time / m / 2;
	*/ // Same for Y and Z
	
	std::cout << "Object will end up at this cordinates: "<< endRes << std::endl;
	system("pause");
}

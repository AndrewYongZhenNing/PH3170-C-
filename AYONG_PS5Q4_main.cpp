#include <iostream>
#include <cmath>
#include <string>
#include "vector.h"
//#include "vector.cpp"

int main(){

	double pi = 4 * atan(1);

	Vector2D v1 = Vector2D(3, 4, "Cartesian");
	Vector2D v2(5, 0.5, "Polar");
	Vector2D v3 = Vector2D(10,20,"Cartesian");
	Vector2D v4(10,pi/2,"Polar");
	Vector2D v5 = Vector2D();

	std::cout << "Demonstration of Vector classes." << std::endl;

	std::cout << "\nFor x = 3, y = 4, the vector, v1 is: " << std::endl;
	v1.print();

	std::cout << "\nFor R = 5, theta = 0.5, v2 is: " << std::endl;
	v2.print();

	std::cout << "\nThe vector v1 multiplied by a scalar, 5, is: " << std::endl;
	v1 = v1 * 5;
	v1.print();

	std::cout << "\nThe vector v2 divided by a scalar, 5, is: " << std::endl;
	v2 = v2 / 5;

	std::cout << "\nThe vector v5, which is the sum of v3 (x = 10, y = 20) and v4 ( R = 10, theta = pi/2), is: " << std::endl;
	v5 = v3 + v4;
	v5.print();

	std::cout << "\nThe vector v4 (x = 10, y = 20) added to v4 (R = 10, theta = pi/2) is: " << std::endl;
	v4.add(v3);
	v4.print();


	v1.rotate(pi);
	v1.print();

}

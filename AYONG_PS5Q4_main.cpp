#include <iostream>
#include <cmath>
#include <string>
#include "vector.h"
// #include "vector.cpp" //included exclusively for running on Ubuntu

int main(){

	double pi = 4 * atan(1);

	Vector2D v1 = Vector2D(3, 4, "Cartesian");
	Vector2D v2(5, 0.5, "Polar");
	Vector2D v3 = Vector2D(10,20,"Cartesian");
	Vector2D v4(10,pi/2,"Polar");
	Vector2D v5 = Vector2D();
  Vector2D v6(5,12,"Cartesian");
  Vector2D v7(12,4,"Cartesian");
  Vector2D v8 = Vector2D(4,9,"Cartesian");

	std::cout << "Demonstration of the Vector class." << std::endl;

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

	std::cout << "\nThe vector v3 (x = 10, y = 20) added to v4 (R = 10, theta = pi/2) is: " << std::endl;
	v4.add(v3);
	v4.print();

	std::cout << "\nThe magnitude of v5 is: " << std::endl;
	double magnitude = v5.get_magnitude();
	std::cout << magnitude << std::endl;

  std::cout <<"\nThe angle of v4 is: " << std::endl;
  double angle = v4.get_angle();
  std::cout << angle << "rad" << std::endl;

  std::cout << "\nThe rotation of v6 (x = 5, y = 12) by the angle pi is: " << std::endl;
  v6.rotate(pi);
	v6.print();

  std::cout <<"\nThe dot product between v7 (x = 12, y = 4) and v8 (x = 4, y = 9) is:" << std::endl;
  double dot_result = v7.dot(v8);
  std::cout << dot_result << std::endl;

  std::cout "End of demonstration." << std::endl;

}

#include <cmath>
#include <iostream>
#include <string>
#include "vector.h" // exclusively on the Ubuntu machine

Vector2D::Vector2D(double x, double y, std::string Coordinate){ // if Cartesian, input x and y respectively, if Polar, input radius and angle respectively

	if (Coordinate == "Cartesian" || Coordinate == "cartesian"){
		valid_coordinate = true;
		_x = x;
		_y = y;
	}

	else if (Coordinate == "Polar" || Coordinate == "polar"){
		valid_coordinate = true;
		_x = x*cos(y); // converts polar to Cartesian, for easier algebraic manipulation later
		_y = x*sin(y);
	}

	else{
		valid_coordinate = false;
		std::cerr << "Invalid coordinate system. Please try again." << std::endl;

	}

	//initialises a rotation matrix here:
	// there is an error with this definition of 2x2 array on the heap: need help
	// double** rotation_matrix = new double*[2];// define an array with two columns first
	// for (int i = 0; i < 2; i++){
	//   rotation_matrix[i] = new double[2]; // add one row for each column, ie total is 2 row 2 column: 2x2 matrix
	// }

}

Vector2D::Vector2D() : _x(0), _y(0){};


Vector2D::Vector2D(const Vector2D &rhs){
	_x = rhs._x;
	_y = rhs._y;
}
Vector2D::~Vector2D(){

	// delete [] rotation_matrix; // explicitly tell destructor to delete the 2D array allocated on the heap

} // destructor

Vector2D Vector2D::operator*(int scalar){
	Vector2D temp;
	temp._x = _x*scalar;
	temp._y = _y*scalar;
	return temp; // here one returns temp as an object that holds the new vector; in main, it would be something like Vector2D vector2 = vector1*5, where vector2 is equal to the new temp
}

Vector2D Vector2D::operator/(int scalar){
	Vector2D temp;
	temp._x = _x / scalar;
	temp._y = _y / scalar;
	return temp;
}

Vector2D& Vector2D::operator=(const Vector2D &rhs){

	if (this != &rhs){ // if lhs does not equal to whatever the object is on the rhs, let lhs variables equal to rhs variables
		_x = rhs._x;
		_y = rhs._y;
	}

	return *this;

}

Vector2D Vector2D::operator+(const Vector2D &rhs){
	Vector2D temp;
	temp._x = _x + rhs._x;
	temp._y = _y + rhs._y;
	return temp;
}

void Vector2D::add(const Vector2D &rhs){
	_x = _x + rhs._x;
	_y = _y + rhs._y;

}

double Vector2D::get_magnitude(){

	return sqrt(pow(_x, 2) + pow(_y, 2));

}

double Vector2D::get_angle(){
	return atan(_y / _x);
}

double Vector2D::dot(const Vector2D &rhs){
	return _x*rhs._x + _y*rhs._y;
}

void Vector2D::print(){

	std::cout << _x << "i + " << _y << "j" << std::endl;
}

void Vector2D::rotate(double angle){
	_x = cos(angle)*_x - sin(angle)*_y;
	_y = sin(angle)*_x + cos(angle)*_y;
}

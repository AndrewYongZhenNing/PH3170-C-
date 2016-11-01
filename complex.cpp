#include <iostream>
#include <string>
#include <cmath>
#include "complex.h"

// Complex::Complex(double real, double imaginary) : _re(real), _im(imaginary){} // new way of initialising the private values with values given by users
Complex::Complex(double real, double imaginary, std::string Coordinate){

	if (Coordinate == "Cartesian" || Coordinate == "cartesian"){
		valid_coordinate = true;
		_re = real;
		_im = imaginary;
	}

	else if (Coordinate == "Polar" || Coordinate == "polar"){
		valid_coordinate = true;
		_re = real*cos(imaginary);
		_im = real*sin(imaginary);
	}

	else{
		valid_coordinate = false;
		std::cerr << "Invalid coordinate system. Please try again." << std::endl;

	}




}
Complex::Complex() : _re(0), _im(0){}; // used for temp variables in operators
Complex::~Complex(){

	// std::cout << "Objects successfully destructed." << std::endl; // this line shows that destructor is only called after main() function is exited.
}


Complex Complex::operator*(int scalar){
	Complex temp; // temp is a temporary variable(it is actually a temporary Complex with no values inisialised)
	temp._re = _re*scalar;
	temp._im = _im*scalar;
	return temp; // returning temp returns an object that holds the new complex number, the components can be viewed using the return_real or return_img functions
}

Complex Complex::operator/(int scalar){
	Complex temp;
	temp._re = _re / scalar;
	temp._im = _im / scalar;
	return temp;
}

Complex Complex::operator+(const Complex &rhs){ // const Complex &rhs ensures that the complex number of &rhs does not get changed after operations
	Complex temp; // does this operation change the value of the lhs complex number?
	temp._re = _re + rhs._re;
	temp._im = _im + rhs._im;
	return temp;

}

Complex& Complex::operator=(const Complex &rhs){

	if (this != &rhs){ // if lhs does not equal to whatever the object is on the rhs, let lhs variables equal to rhs variables
		_re = rhs._re;
		_im = rhs._im;
	}

	return *this;

}

double Complex::return_real(){ // class::object format, in a class define an object called return_real that returns the real value
	return _re;
}

double Complex::return_img(){
	return _im;
}

double Complex::abs_complex(){
	return sqrt(pow(_re, 2) + pow(_im, 2));

}

void Complex::print(){
	if (valid_coordinate == true){
		std::cout << _re << " + " << _im << "i" << std::endl;

	}

	else if (valid_coordinate == false){
		std::cerr << "Error, cannot print complex number. Please ensure that the coordinate system is correct." << std::endl;

	}

}

//double polar_form(){

//}

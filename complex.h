#ifndef _KLASS_
#define _KLASS_

#include <string>

class Complex{ // create a class called Complex that has operations for complex number, z = a + i*b

public:
	// N.B: constructor MUST be the same name as class
	// Complex(double real_part, double imaginary_part); // Complex constructor takes two variable, the real and the imaginary part
	Complex(double real_part, double imaginary_part, std::string Coordinate);
	Complex(); // initialise a DEFAULT constructor that takes no variable; maybe not useful
	~Complex(); //define a destructor, empty now


	//note that the operators below might be missing an extra Complex term on the lhs
	Complex operator*(int scalar); // for question 3a
	Complex operator/(int scalar); // for question 3b
	Complex operator+(const Complex &rhs); //for question 3c, adding two complex objects together
	Complex& operator=(const Complex &rhs); // for output of new complex number from operations between two complex numbers

	double return_real(); // returns the real part; for question 3d
	double return_img(); // returns the imaginary part; for question 3e
	double abs_complex(); // returns the absolutely value of the complex number; for question 3f

	// void polar_form(); // as a future project, maybe return an array of complex number parameters from Cartesian into polar parameters
	void print();

private:
	double _re;
	double _im;
	bool valid_coordinate;

};

#endif

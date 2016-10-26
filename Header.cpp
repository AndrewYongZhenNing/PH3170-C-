#include "Header.h"
#include <iostream>
#include <cmath>

Measurement::Measurement(double meas, double error) : _meas(meas), _error(error){} // new way of initialising
Measurement::Measurement() : _meas(0), _error(0){} // sets a default value for _meas and _error to 0



Measurement::~Measurement(){ // defining my destructor

}

double Measurement::FractionalError(){
	return _error / _meas;
}

void Measurement::Print(){
	std::cout << _meas << "	" << _error << std::endl;
}

void Measurement::Add(const Measurement &rhs){
	_meas = _meas + rhs._meas; // this changes the _meas value to _meas from one object plus with _meas from the other
	_error = sqrt(pow(_error, 2) + pow(rhs._error, 2));
}

Measurement Measurement::operator+(const Measurement &rhs){
	Measurement temp; // let temp be a temporary variable, just like temp in the swap function; temp requires two arguments because it is like calling Measurement try1(input variable 1 and 2 here)
	temp._meas = _meas + rhs._meas; // the _meas in the object temp is the variable of one object plus with the variable of another object
	temp._error = sqrt(pow(_error, 2) + pow(rhs._error, 2));
	// for more info, refer to page 54/55 of PDF
}
Measurement Measurement::operator+(int constant){
	Measurement temp; // let temp be a temporary variable, just like temp in the swap function; temp requires two arguments because it is like calling Measurement try1(input variable 1 and 2 here)
	temp._meas = _meas + constant; // the _meas in the object temp is the variable of one object plus with the variable of another object
	temp._error = _error;
	return temp;
	// for more info, refer to page 54/55 of PDF
}

Measurement Measurement::operator=(const Measurement &rhs){
	if (this != &rhs){ // 'this' is used such that when you create an object, called m3 for example, and set it equals to another object, say m1, it will compare 'this' object, ie, m3 and see if it is equal to the rhs bit, ie m1, and if not, the following implementation occurs
		_meas = rhs._meas;
		_error = rhs._error; 
	}

}

Measurement Measurement::operator-(const Measurement &rhs){
	Measurement temp;
	temp._meas = _meas - rhs._meas;
	temp._error = sqrt(pow(_error, 2) + pow(rhs._error, 2));
	return temp;
}

Measurement Measurement::operator*(const Measurement &rhs){
	Measurement temp;
	temp._meas = _meas*rhs._meas;
	temp._error = fabs(temp._meas)*sqrt(pow(_error / _meas, 2) + pow(rhs._error / rhs._meas, 2));
	return temp;
}

Measurement Measurement::operator/(const Measurement &rhs){
	Measurement temp;
	temp._meas = _meas/rhs._meas;
	temp._error = fabs(temp._meas)*sqrt(pow(_error / _meas, 2) + pow(rhs._error / rhs._meas, 2));
	return temp;
}
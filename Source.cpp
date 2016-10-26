#include <iostream>
#include "Header.h"

int main(){

	Measurement try1(5, 0.1); // create an object called try1, try1 can call different methods from the Measurement class
	Measurement try2(10, 0.05);

	try1.Print();
	try1.Add(try2); // this changes the try1 value whilst keeping try2 the same

	try1.Print(); // should notice try1 changed now after using Add
	try2.Print();
	//std::cout << try1.FractionalError() << std::endl;

	Measurement trySum = try1 + 10;

}
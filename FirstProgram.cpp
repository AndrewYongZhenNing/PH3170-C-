#include <iostream>

int square(int value); //Forward declaration of function to be used in main

int main()
{
	//This is a comment, the main execution thread of your program is defined within the 'main' function

	int value_A = 5;
	int value_B = 3;
	int value_C = value_A * value_B;

	std::cout << "Hello, world!" << std::endl;
	std::cout << "Result of multiplication = " << value_C << std::endl;

	//Try and call a function
	int result = square(7);
	std::cout << "Square of 7 is " << result << std::endl;
	
	int var = 5;
	int& test = var;
	std::cout << "test = " << test << std::endl;

}

int square(int value){
	return value*value;
}

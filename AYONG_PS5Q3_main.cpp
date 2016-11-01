
#include "complex.h"
#include "complex.cpp" // unnecessary on Windows, required for Ubuntu


int main(){
  std::cout << "Testing commences." << std::endl;

  // Complex z1 = Complex(2,3,"Polar");
  Complex z1(2,3,"Polar");

  Complex z2 = Complex(7,2, "bla");
  //
  Complex z3 = Complex(6,5,"Cartesian");
  Complex z4 = z1*5;
  Complex z5 = z1 + z2;

  z1.print();
  z2.print();
  // z3.print();
  z4.print();
  z5.print();


  std::cout << "Testing ends." << std::endl;
}

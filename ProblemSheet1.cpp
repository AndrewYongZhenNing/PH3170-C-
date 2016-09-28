#include <iostream>
#include <cmath>

float quadratic(signed a,signed b,signed c){
  float x1 = (-b+(sqrt(pow(b,2)-4*a*c)))/(2*a);
  float x2 = (-b-(sqrt(pow(b,2)-4*a*c)))/(2*a);
  return x1, x2; //how to extract 2 values in one function?

float area(float a, float b, float c){
  
}
}

int main(){
  signed a = 0;
  signed b = 0;
  signed c = 0;
  std::cout << "Enter a,b,c in a general quadratic equation: " << std::endl;
  std::cin >> a >> b >> c;
  float quadratic_result = quadratic(a,b,c);
  // std::cout << quadratic_result << std::endl;
  std::cout << "Roots of the quadratic equation \n" << "x1= " << quadratic_result << "  x2= " << quadratic_result << std::endl;
}

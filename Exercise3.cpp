#include <iostream>
#include <cmath>

/* this is another way of commenting
*it allows for comments on multiple lines
* and here is the end of the comments
*/
double pi = 3.141592;

float period(float value){
  float gravity = 9.81;
  return 2*pi*sqrt(value/gravity);
}

float trigonometric_identity(float value){
  return pow(cos(value*pi/360),2) + pow(sin(value*pi/360),2);
}

//test trigonometry identity
int main(){
  std::cout << "Enter angle: " <<std::endl; //provides instruction for input
  int angle = 0; //define a null integer first, to be replaced with input value
  std::cin >> angle; // asks user to give an angle (in degrees) as input
  float length = 0.5;
  float period_result = period(length);
  float trig_result = trigonometric_identity(angle);
  std::cout << "The period is, T= " << period_result << "s" << std::endl;
  // std::cout << "The period is, T= " << period_result << "s" << std::endl;
  std::cout << trig_result << std::endl;

}

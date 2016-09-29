#include <iostream>
#include <cmath>
#include "PS1f.h" // header file includes functions on horizontal distance and vertical height

int main(){

  // Question 4a
  std::cout << "Question 4a\n" << std::endl;
  int t1, t2, t3 = 0;

  // Input data
  std::cout << "Enter time: \n(note that time must be greater than 0)\n" << std::endl;
  std::cin >> t1;
  std::cin >> t2;
  std::cin >> t3;

  // Define physical values
  const float pi = 3.141592;
  const float g = -9.81; //gravitational acceleration (ms^(-2))
  int velocity = 50; //ms^(-1)
  int theta = 30; // in degrees
  float v_y = velocity*sin((theta*pi)/180);
  float v_x = velocity*cos((theta*pi)/180);
  int original_height = 1; // above 'ground level', measured in m


  // Computes the range and height of the trajectory during different times
  float horizontal_distance_1 = horizontal_distance(v_x,t1);
  float horizontal_distance_2 = horizontal_distance(v_x,t2);
  float horizontal_distance_3 = horizontal_distance(v_x,t3); // these three floats compute the horizontal range of the trajectory

  float vertical_height_1 = vertical_height(g,v_y,t1, original_height);
  float vertical_height_2 = vertical_height(g,v_y,t2, original_height);
  float vertical_height_3 = vertical_height(g,v_y,t3, original_height); // the +1 is to account for the initial height of 1m above 'ground level'

  // Computes the time at which the ball hits ground level
  float t_1 = (-v_y+sqrt(pow(v_y,2)-4*0.5*g*original_height))/(2*0.5*g); // rearrangement of the equation s = s_0 + ut + 0.5*a*t^2, where s is 0 at ground level
  float t_2 = (-v_y-sqrt(pow(v_y,2)-4*0.5*g*original_height))/(2*0.5*g); // t_1 and t_2 are the two possible times at which the ball hits the ground level

  std::cout << "\nAt time, t = " << t1 << "s:\nThe horizontal distance, R = " << horizontal_distance_1 << "m\nThe vertical height, h = " << vertical_height_1 << "m above ground level" << std::endl;
  std::cout << "\nAt time, t = " << t2 << "s:\nThe horizontal distance, R = " << horizontal_distance_2 << "m\nThe vertical height, h = " << vertical_height_2 << "m above ground level" << std::endl;
  std::cout << "\nAt time, t = " << t3 << "s:\nThe horizontal distance, R = " << horizontal_distance_3 << "m\nThe vertical height, h = " << vertical_height_3 << "m above ground level" << std::endl;

  std::cout << "\nThe possible times at which the ball hits ground level are:\n" << "t = " << t_1 << "s or t = " << t_2 << "s" << std::endl;
  std::cout << "\nSince one is considering time to be positive, the time at which the ball hits ground level after being launched is, t = " << t_2 << "s" << std::endl;

  // Question 4b
  std::cout << "\nQuestion 4b\n" << std::endl;

  // Angles
  float angle_A = 57.6; // degrees
  float angle_B = 40.5;
  float angle_C = 180 - angle_B - angle_A;

  //Lengths
  float side_a = 9.5; // in arbitrary length unit
  float side_b = side_a*(sin(angle_B*pi/180)/sin(angle_C*pi/180));
  float side_c = side_a*(sin(angle_A*pi/180)/sin(angle_C*pi/180));

  std::cout << "The remaining angle, C = " << angle_C << " degrees" << std::endl;
  std::cout << "The remaining side, \nb = " << side_b << "  " << "c = " << side_c << std::endl;

  // Question 4c
  std::cout << "\nQuestion 4c\n" << std::endl;

  double try_1, try_2, try_3, try_4, try_5 = 0;

  std::cout << "Enter five eleven-digit numbers to check for the expression e^(ln(x)) = x" << std::endl;
  std:: cin >> try_1;
  std:: cin >> try_2;
  std:: cin >> try_3;
  std:: cin >> try_4;
  std:: cin >> try_5;

  exponent_check(try_1); //implement function here to avoid declaring even more variables
  exponent_check(try_2);
  exponent_check(try_3);
  exponent_check(try_4);
  exponent_check(try_5);

}

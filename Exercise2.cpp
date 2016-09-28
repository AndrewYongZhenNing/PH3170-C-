#include <iostream>

float sphere_volume(float value);
float distance(int value1, float value2);

int main(){
  float radius = 5.6;
  int t_flight = 15;
  float gravity = 9.81;

  float volume_result = sphere_volume(radius);
  float distance_result = distance(t_flight, gravity);

  std::cout << "The volume of the sphere is " << volume_result << std::endl;
  std::cout << "The volume of the sphere is " << distance_result << std::endl;
}

float sphere_volume(float value){
  return (4./3)*3.141592*value*value*value;
}

float distance(int value1, float value2){
  return 1./2*value2*value1*value1;
}

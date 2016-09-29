#ifndef _functions_
#define  _functions_

float horizontal_distance (float x_velocity, int Time){
  return x_velocity*Time;
}

float vertical_height(const float acceleration, float y_velocity, int Time, int height_offset){
  return 0.5*acceleration*pow(Time,2) + y_velocity*Time + height_offset;
}

void exponent_check(double x){
  std::cout << "\nFor x = " << x << "\ne^(ln(" << x << ")) = " << exp(log(x)) << std::endl;
}
#endif

#include <iostream>
#include <cmath>
#include <string>
#include "vector.h"
#include "vector.cpp"

int main(){

  double pi = 4*atan(1);
  Vector2D v1 = Vector2D(3,4,"Cartesian");
  Vector2D v2 = Vector2D(5,0.5, "Polar");
  v1.rotate(pi);
  v1.print();
}

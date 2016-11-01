#ifndef _KLASS_
#define _KLASS_

#include <string>

class Vector2D{
public:
  Vector2D(double x, double y, std::string Coordinate); // constructor; // if Cartesian, input x and y respectively, if Polar, input radius and angle respectively
  Vector2D(); // default constructor
  Vector2D(const Vector2D &rhs); // copy consturctor
  ~Vector2D(); // destructor

  Vector2D operator*(int scalar);
  Vector2D operator/(int scalar);
  Vector2D operator=(const Vector2D &rhs);
  Vector2D operator+(const Vector2D &rhs);

  void add(const Vector2D &rhs); // use void because the method acts on the object and changes its value
  double get_magnitude();
  double get_angle(); // angle from the x-axis in counter-clockwise direction
  void rotate(double angle);
  double dot(const Vector2D &rhs);

  void print();



private:
  double _x;
  double _y;
  bool valid_coordinate; // boolean is used to check if the argument regarding coordinate system is a valid one
  double *rotation_matrix;

};

#endif

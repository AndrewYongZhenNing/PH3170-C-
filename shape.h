#ifndef _SHAPEklass
#define _SHAPEklass
#include <iostream>
#include <cmath>

class Shape{

public:

  Shape(float s1, float s2, float s3); //first constructor

  ~Shape(); //destructor initialised explicitly, just for good practice

  virtual float getArea(); // always needs to define virtual function before compiling

  virtual float getVolume();

  static double pi;

protected: // changed from private to protected in order for derived classe to inherit these parameters without altering them

  float _side1;
  float _side2;
  float _side3;


};


class Cuboid: public Shape{

public:

  Cuboid(float side); //the case of a cube
  Cuboid(float length, float width, float height); // the case of non-cube cuboids

  float getArea();
  float getVolume();


};

class Pyramid:public Shape{

public:
  Pyramid(float length, float width, float height);

  float getArea();
  float getVolume();
};

class Sphere: public Shape{

public:

  Sphere(float radius);

  float getArea();
  float getVolume();

};

class Parallelepiped:public Shape{

public:
  Parallelepiped(float lenth, float width, float height, float angle);

  float getArea();
  float getVolume();

private:

  float _rad; //specially for parallelepiped only

};

class Ellipsoid:public Shape{

public:
  Ellipsoid(float a, float b, float c); //where a,b,c are semi-axes

  float getArea();
  float getVolume();
  
};

#endif

#include "shape.h"

// BASE CLASS: SHAPE
Shape::Shape(float s1, float s2, float s3): _side1(s1), _side2(s2), _side3(s3){}

Shape::~Shape(){};

float Shape::getArea(){
  return 0;
}

float Shape::getVolume(){
  return 0;
}

double Shape::pi = 3.141592;

// DERIVED CLASS: CUBOID

Cuboid::Cuboid(float side):Shape(side,side,side){ //cube case

  std::cout << "Constructing cuboid now...length: " << _side1 << " width: " << _side2 << " height: " << _side3 << std::endl; //a line to test

}

Cuboid::Cuboid(float length, float width, float height):Shape(length,width,height){ //non-cube case

  std::cout << "Constructing cuboid now...length: " << _side1 << " width: " << _side2 << " height: " << _side3 << std::endl; //a line to test

}

float Cuboid::getArea(){ // generalised surface area for cubes and cuboids
  return 2*(_side1*_side2 + _side1*_side3 + _side2*_side3);
}

float Cuboid::getVolume(){
  return _side1*_side2*_side3;
}


// DERVIED CLASS: PYRAMID

Pyramid::Pyramid(float length, float width, float height):Shape(length,width,height){ //non-cube case

  std::cout << "Constructing pyramid now...length: " << _side1 << " width: " << _side2 << " height: " << _side3 << std::endl; //a line to test

}

float Pyramid::getArea(){
  return _side1*_side2 + _side1*sqrt(pow(_side3,2)+0.25*pow(_side2,2)) + _side2*sqrt(pow(_side3,2)+0.25*pow(_side1,2));
}

float Pyramid::getVolume(){
  return 1./3 * _side1*_side2*_side3;
}

// DERVIED CLASS: SPHERE

Sphere::Sphere(float radius):Shape(radius,0,0){

  std::cout << "Constructing a sphere now...radius: " << _side1 << std::endl;

}

float Sphere::getArea(){
  return 4*pi*pow(_side1,2);
}

float Sphere::getVolume(){
  return 4./3 * pi * pow(_side1,3);
}

// DERIVED CLASS: PARALLELEPID

Parallelepiped::Parallelepiped(float length, float width, float height, float angle):Shape(length,width,height),_rad(angle){}

float Parallelepiped::getArea(){
  return 2*(_side1*_side2*sin(_rad)+(_side1*_side3)+(_side2*_side3));
}

float Parallelepiped::getVolume(){
  return _side1*_side2*_side3*sin(_rad);
}

// DERIVED CLASS: ELLIPSOID

Ellipsoid::Ellipsoid(float a, float b, float c):Shape(a,b,c){};

float Ellipsoid::getArea(){
  std::cerr << "Caution: Surface area is only an approximation." << std::endl;
  return 4*pi*pow((1./3) * (pow(_side1*_side2,1.6)+pow(_side1*_side3,1.6)+pow(_side2*_side3,1.6)),1./1.6);
}

float Ellipsoid::getVolume(){
  return 4./3 * pi * _side1*_side2*_side3;
}

//VIRTUAL FUNCTIONS

float Area(Shape &shapes){ // gets the surface area of any shape
  return shapes.getArea();
}

float Volume(Shape &shapes){ // gets the volume of any shape
  return shapes.getVolume();
}

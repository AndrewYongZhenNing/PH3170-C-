#include <iostream>
#include <cmath>
#include <string>
#include "PS3.h"
using namespace std;

float f(float x){
  return 6*pow(x,2) - 17*x - 14;
}

float df(float x){
  return 12*x - 17;
}

float cubic_f(int A, int B, int C, int D, float x){
  return A*pow(x,3) + B*pow(x,2) + C*x + D;
}

float cubic_df(int A, int B, int C, float x){
  return 3*A*pow(x,2) + 2*B*x + C;
}

void Newton_Raphson_r(int A, int B, int C, int D, int n_max, float x){
  // _r stands for recursive
  // N.B generalised for Question 3
  float function = A*pow(x,n_max) + B*pow(x,n_max-1) + C*pow(x,n_max-2) + D*pow(x,n_max-3); //generalising to cubic polynomial
  float function_derivative = n_max*A*pow(x,n_max-1) + (n_max-1)*B*pow(x,n_max-2) + (n_max-2)*C*pow(x,n_max-3) + (n_max-3)*D*pow(x,n_max-4); //generalising its derivative

  float delta_x = 1; // set to 1 just the initalise it
  float x_0 = x; // to be seeded
  float x_1;

  cout << "[PROGRESS] Root precision dx = " << delta_x << endl;

  x_1 = x_0 - function/function_derivative; //- f(x_0)/df(x_0);
  delta_x = x_1 - x_0;

  if(delta_x <0.1){
    cout << "\nCalculation completed. \nRoot, x = " << x_1 << "\nRoot precision dx = " << delta_x << "\n \n" << endl;
  }

  else{
    Newton_Raphson_r(A,B,C,D,n_max,x_1);
  }

}


void vector_transform(){

  string form;

  start:
    cout << "Select a coordinate system: Cartesian or Polar?";
    cin >> form;

    float x;
    float y;
    float magnitude;
    float r;
    float theta;

    if(form == "Cartesian" or form == "cartesian"){

      cout << "Input parameters: \nx = ";
      cin >> x;
      cout << "y = ";
      cin >> y;

      magnitude = sqrt(pow(x,2)+pow(y,2));
      r = magnitude;
      theta = atan(y/x) * 180./(atan(1)*4); //converts to degrees

      cout << "Given Cartesian coordinates, \nMagnitude, |v| = " << magnitude << "\nthe polar parameters are: \nr = " << r << "\ntheta = " << theta << " degrees" << endl;
    }

    else if(form == "Polar" or form == "polar"){

      cout << "Input parameters: \nr = ";
      cin >> r;
      cout << "theta(degrees) = ";
      cin >> theta; //converts degrees to radians

      magnitude = r;
      x = r*cos(theta*(atan(1)*4.)/180);
      y = r*sin(theta*(atan(1)*4.)/180);

      cout << "Given polar coordinates, \nMagnitude, |v| = " << magnitude << "\nthe Cartesian parameters are: \nx = " << x << "\ny = " << y << endl;
    }

    else{
      cout << "Invalid choice. Please try again.\n";
      goto start;
    }

}

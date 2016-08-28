#include <iostream>
#include <string>
#include <cmath>
#include "PS3.h"
#include "PS3f.cpp"
using namespace std;


int main(){

  // QUESTION 3
  //QUESTION 3a - non-recursive Newton-Raphson method

  cout << "Question 3a \n" << endl;

  float x_0; // what if I use double instead of float?
  float x_1;
  float dx = 1; // sets a certain value above 0.1 to initiate while loop

  cout << "Enter seed for x: ";
  cin >> x_0;

  cout << "[PROGRESS] Root precision dx = " << dx << endl;

  while (dx >= 0.1){ //keeps on improving x until dx<0.1

    x_1 = x_0 - f(x_0)/df(x_0); // Newton-Raphson applied here

    dx = x_1 - x_0;

    cout << "[PROGRESS] Root precision dx = " << dx << endl;

    if(dx>=0.1){

      x_0 = x_1; // now the new x_0 takes the x_1 value, frees up x_1 for the next iteration if dx >0.1

    }

    else{
      cout << "\nCalculation completed. \nRoot, x = " << x_1 << "\nRoot precision dx = " << dx << endl;
    }

    }

  // QUESTION 3b - recursive Newton-Raphson method
  //N.B using variables declared in QUESTION 3a, float x_0, float x_1 etc...
  cout << "\nQuestion 3b \n" << endl; //space to separate questions

  Newton_Raphson_r(6,-17,-14,0,2,x_0); //void function prints out results

  // QUESTION 3c - generalising to third-degree polynomial

  cout << "\nQuestion 3c \n" << endl; //space to separate questions

  int p = 1;
  int n;
  cout << "Enter highest order, n:";
  cin >> n;

  while(p<=n){
    float x_0c;
    cout << "Enter seed for x" << p << " :";
    cin >> x_0c;

    Newton_Raphson_r(2,7,2,-3,n,x_0c);

    p++;

  }
  

  // QUESTION 4 - 2D CARTESIAN-POLAR VECTORS

  // vector_transform();

  return 0;
}
//
// void testing(){
//   cout << "This works!" << endl;
// }

// int test(int x){
//   return x+1;
// }

#include <iostream>
#include <cmath>
#include <ctype.h>


void square(int &x){
  x = x*x;
}

void pointer_square(int* x){
  *x = *x**x;
}

void trigo(float radian, float &sine, float &cosine ){
  sine = sin(radian);
  cosine = cos(radian);
}

void pointer_trigo(float radian, float* sine, float* cosine ){
  *sine = sin(radian);
  *cosine = cos(radian);

}

int main(){

  //using reference '&'

  std::cout << "Exercise with Referencing\n" << std::endl;

  int initial = 15;
  int &refInit = initial;
  refInit /= 5;
  std::cout << initial << std::endl;

  square(initial);

  std::cout << initial << std::endl;

  float sineVal = 0.0;
  float cosineVal = 0.0;
  float angle = 0.5;

  trigo(angle, sineVal, cosineVal);

  std::cout << sineVal << "," << cosineVal << "\n" << std::endl;

  //using pointers

  std::cout << "Exercise with Pointers\n" << std::endl;

  initial = 15; //re-initialise the value to 15 as in the beginning of exercise
  int *ptrInit = &initial;
  *ptrInit +=5;

  std::cout<< initial << std::endl;

  pointer_square(&initial);

  std::cout<< initial << std::endl; //do i expect 400?

  sineVal = 0.0;
  cosineVal = 0.0;

  pointer_trigo(angle, &sineVal, &cosineVal);

  std::cout << sineVal << "," << cosineVal << "\n" << std::endl;

  //arrays

  std::cout << "Exercise with Arrays\n" << std::endl;
  std::cout << "Question 1\n" << std::endl;

  int myArray[20] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
  int size = sizeof(myArray)/sizeof(int);


  for(int i = 0; i < size; i ++){
    if( myArray[i] == 1){
      std::cout << "This for-loop can count to 20!" << std::endl;
    }

    std::cout << myArray[i] << std::endl;

    if (myArray[i] == 20){
      std::cout << "Ta-da! Hope you are impressed!" << std::endl;
    }

  }

  std::cout << "\nQuestion 2\n" << std::endl;

  char rhul[13] = "RHULPHYS3170"; // 12 characters + null character \0 = 13
  int rhul_size = sizeof(rhul)/sizeof(char);
  int number = 0;

  for(int k = 0; k <= rhul_size; k++){
      if (isdigit(rhul[k])){
        number += 1;
      }
  }

  std::cout << "Number of digits in " << rhul << " = " << number << std::endl;


  std::cout << "\nQuestion 3\n" << std::endl;

  int Fibonacci[45] = {};


  for(int n = 0; n < 46; n++){
    if (n ==0){ //or n==2
      Fibonacci[n] = 1; //0th value
      n +=1;
    }

    if (n == 1){
      Fibonacci[n] = 1;
      n+=1;
    }


    Fibonacci[n] = Fibonacci[n-2] + Fibonacci[n-1];

  }

  int Fibonacci_size = sizeof(Fibonacci)/sizeof(int);



  for(int j = 0; j<=Fibonacci_size; j+=3){ //=+3 to ensure always every third term
    if(j ==0){
      std::cout << "Every third term in the Fibonacci sequence: " << std::endl;
    }

    std::cout << Fibonacci[j] << std::endl;

  }

}

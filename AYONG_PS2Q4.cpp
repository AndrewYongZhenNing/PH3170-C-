#include <iostream>
#include <string>
#include "AYONG_PS2Q4.h"

int main(){

  //Question 4a

  // int counter = 0;
  // int i = 2;
  // long int fibonacci[70] = {0,1}; // array for all fibonacci; put 30 as an estimation
  // long int even_fibonacci[20] = {}; // array for even fibonacci
  // long int sum = 0;
  // long int fibonacci_length = sizeof(fibonacci)/sizeof(long int);
  // long int even_length = sizeof(even_fibonacci)/sizeof(long int);
  //
  //
  // while(i < fibonacci_length){ // gets the first 50 fibonacci numbers
  //
  //   // std::cout<< i << std::endl; //progress checker
  //
  //   fibonacci[i] = fibonacci[i-1] + fibonacci[i-2]; //arrays are causing Segmentation Fault (core dumped)
  //   std::cout << fibonacci[i] << std::endl;
  //
  //   i++;
  //
  // }
  //
  // for (int j = 0; j < fibonacci_length; j+= 1){ // search for even fibonacci numbers happens here
  //   std::cout << "j = " << j << " Current number: " << fibonacci[j] << std::endl;
  //   if(fibonacci[j]%2 == 0 and fibonacci[j] >0 and even_fibonacci[19] == 0){
  //     even_fibonacci[counter] = fibonacci[j];
  //     counter ++;
  //   }
  //
  // }
  //
  // for (int k = 0; k < even_length; k++){ //summation happens here
  //   std::cout << "k = " << k << " Current number: " << even_fibonacci[k] << std::endl; // progress checker
  //   sum += even_fibonacci[k];
  // }
  //
  // std::cout << "Process completed." << std::endl;
  //
  // std::cout << "Total sum of the first 20 even numbers in the Fibonacci sequence are: " << sum << std::endl;
  //
  //Question 4b

  sum_Fibonacci();



}

void sum_Fibonacci(){

  int lower_boundary = 0;
  int upper_boundary = 0;
  std::string loop_selection;


  std::cout << "This program sums the Fibonacci numbers" << std::endl;

  boundary:
    std::cout << "Enter lower boundary:" << std::endl; // need exception to catch different variable types
    std::cin >> lower_boundary;

    if(lower_boundary <0){
      std::cout << "Error: the lower boundary has been assigned a negative value. Please ensure that the boundaries are positive integers." << std::endl;
      goto boundary;
    }

    std::cout << "Enter upper boundary:" << std::endl;
    std::cin >> upper_boundary;

    if(upper_boundary <0){
      std::cout << "Error: the upper boundary has been assigned a negative value. Please ensure that the boundaries are positive integers." << std::endl;
      goto boundary;
    }

    if(lower_boundary>upper_boundary){
      std::cout << "Error: the lower boundary is greater than the upper boundary. Please try again.\n" << std::endl;
      goto boundary;
    }



  loop_type:
    std::cout << "Sum even, odd, or all Fibonacci numbers?\n(answer with: even/odd/all)" << std::endl;
    std::cin >> loop_selection;

    int counter = 0;
    int i = 2;
    unsigned long long int fibonacci[80] = {0,1}; //set length as 100 for now, since numbers grow exponentially larger, first 100 fibonacci numbers should suffice
    unsigned long long int even_fibonacci[upper_boundary-lower_boundary] = {}; // length of array is upper_boundary - lower_boundary on the basis that there will always be fewer even numbers between the two boundaries than total fiboancci numbers in those boundaries
    unsigned long long int odd_fibonacci[upper_boundary-lower_boundary] = {};
    unsigned long int sum = 0;

    int fibonacci_length = sizeof(fibonacci)/sizeof(unsigned long long int);
    int even_fibonacci_length = sizeof(even_fibonacci)/sizeof(unsigned long long int);
    int odd_fibonacci_length = sizeof(odd_fibonacci)/sizeof(unsigned long long int);


    while(i < fibonacci_length){ // gets the first 100 fibonacci numbers

      // std::cout<< i << std::endl; //progress checker

      fibonacci[i] = fibonacci[i-1] + fibonacci[i-2]; //arrays are causing Segmentation Fault (core dumped)
      std::cout << fibonacci[i] << std::endl;

      i++;

    }


    if (loop_selection == "even"){
      //do something

      for (int j = 0; j < fibonacci_length; j++){ // search for even fibonacci numbers happens here

        if(fibonacci[j]%2 == 0 and fibonacci[j] >0 and even_fibonacci[upper_boundary-lower_boundary-1] == 0){
          // std::cout << "j = " << j << " Current number: " << fibonacci[j] << std::endl; // progress checker
          even_fibonacci[counter] = fibonacci[j];
          counter ++;
        }

      }

      for (int i = lower_boundary; i < upper_boundary+1; i++){ //comparison from lower boundary onwards begins here
        for (int k = 0; k < even_fibonacci_length; k++){
          if (even_fibonacci[k] == i){
            sum += even_fibonacci[k];

          }
        }

      }
      std::cout << "Process completed.\nThe sum of even Fibonacci numbers between " << lower_boundary << " and " << upper_boundary << " is, total = " << sum << std::endl;
    }

    else if (loop_selection == "odd"){
      //do something else
      for (int j = 0; j < fibonacci_length; j+= 1){ // search for odd fibonacci numbers happens here

        if(fibonacci[j]%2 == 1 and fibonacci[j] >0 and odd_fibonacci[lower_boundary-upper_boundary-1] == 0){
          // std::cout << "j = " << j << " Current number: " << fibonacci[j] << std::endl; // progress checker
          odd_fibonacci[counter] = fibonacci[j];
          counter ++;
        }

      }

      for (int i = lower_boundary; i < upper_boundary+1; i++){ //comparison from lower boundary onwards begins here
        for (int k = 0; k < odd_fibonacci_length; k++){
          if (odd_fibonacci[k] == i){
            sum += odd_fibonacci[k];
          }
        }
      }
      std::cout << "Process completed.\nThe sum of odd Fibonacci numbers between " << lower_boundary << " and " << upper_boundary << " is, total = " << sum << std::endl;
    }

    else if (loop_selection == "all"){
      //do something else
      for (int i = lower_boundary; i < upper_boundary+1; i++){ //comparison from lower boundary onwards begins here
        for (int l = 0; l < fibonacci_length; l++){
          if (fibonacci[l] == i){
            sum += fibonacci[l];
          }
        }
      }
      std::cout << "Process completed.\nThe sum of all Fibonacci numbers between " << lower_boundary << " and " << upper_boundary << " is, total = " << sum << std::endl;
    }

    else{
      std::cout << "Command unknown. Please try again and check for spelling errors.\n" << std::endl;
      goto loop_type;
    }



}

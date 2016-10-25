#include <iostream>
#include "AYONG_PS4Q4.h"

int main(){

  std::cout << "Question 4a" << std::endl;

  /*Example
  // int p = 5;
  // int q = 6;
  // int *r;
  // r = &q;

  // std::cout << *r << std::endl; // giving the * dereferences it; without the star gives the memory address
  */


  int sequence_1[]= {1,3,12,-1,47,4,4,23,35,12,34,34,809};
  int sequence_1_length = sizeof(sequence_1)/sizeof(int);

  int sequence_2[] = {945,432,134,79,47,4,90,0,-56,32,78};
  int sequence_2_length = sizeof(sequence_2)/sizeof(int);

  

  int sequence[24] = {};

  int test[] = {1,3,12,-1,47,4,4,23,35,12,34,34,809,945,432,134,79,47,4,90,0,-56,32,78};
  int test_len = sizeof(test)/sizeof(int);

  // std::cout << sequence_1[31] << std::endl; // beyond the allocated index, the array outputs random values

  sort(sequence_1, sequence_1_length);
  sort(sequence_2, sequence_2_length);

  std::cout << "Question 4b" << std::endl;

  merge(sequence, sequence_1, sequence_1_length, sequence_2, sequence_2_length);
  // sort(test,test_len);

  std::cout << "Question 4c" << std::endl;

  std::cout << "Please find the solution to Question 4c in the PDF file." << std::endl;

  /*
  best case: if two sorted lists join to become a complete sorted list of ascending order: iteration = 1 (the one iteration that checks it is all in ascending order)
  worst case: if the first value of the second sorted list is smaller than the first value of the first sorted list: iteration = n, where n is the length of the first sorted list
  */


}

void swap(int *left, int *right){

  int temp = *left;
  *left = *right;
  *right = temp;

}

void sort(int sequence[], int length){

  bool sorted = false; // define a sorting boolean; false if not fuly sorted, true if no sorting is required in the sequence
  int iteration_number = 0;

  std::cout << "Consider the following sequence:\n" << std::endl;

  for(int j = 0; j < length; j++){

    std::cout << sequence[j] << " " << std::flush;
    // std::cout << sequence[j] << std::endl;

  }

  std::cout << "\n" << std::endl;

  while (sorted == false){

    // std::cout << "Iteration #" << iteration_number << std::endl;

    int swapped = 0; // swapped is a counter for how many times the swap function was called; the number on swapped will tell us if the sequence is sorted or not; defined here to reset the counter every iteration

    for(int i = 1; i < length; i++){ // go through the sequence, using the swap function if the values are not in ascending order

      if(sequence[i] < sequence[i-1]){

        swap(&sequence[i],&sequence[i-1]);
        // i = 0; // this resets the swap to start from beginning again
        swapped ++;

      }

    }

    iteration_number++;

    if (swapped == 0){

      sorted = true; // this is the exit clause

      std::cout << "\nThe sequence has been sorted. Here are the results:" << std::endl;

      for(int j = 0; j < length; j++){

        std::cout << sequence[j] << " " << std::flush;

      }

      std::cout << "\nTotal number of iterations: " << iteration_number << "\n" << std::endl;

    }


    }


}

void merge(int main_array[], int sequence1[], int sequence1_length, int sequence2[], int sequence2_length){

  for (int i = 0; i < sequence1_length+sequence2_length; i++){

    if(i < sequence1_length){
      main_array[i] = sequence1[i]; // append first sequence into main array
    }

    else if(i >= sequence1_length){
      main_array[i] = sequence2[i-sequence1_length]; // appends second sequence after first sequence is in array
    }
  }

  sort(main_array,sequence1_length+sequence2_length);

}

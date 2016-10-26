#include <iostream>
#include "AYONG_PS4Q4.h"

int main(){

  std::cout << "Question 4a" << std::endl;



  int sequence_1[]= {1,3,12,-1,47,4,4,23,35,12,34,34,809};
  int sequence_1_length = sizeof(sequence_1)/sizeof(int); // computes the size of the sequence here, to be used in functions later

  int sequence_2[] = {945,432,134,79,47,4,90,0,-56,32,78};
  int sequence_2_length = sizeof(sequence_2)/sizeof(int);

  int sequence[24] = {0}; // initialise an array the size of the two arrays combined


  sort(sequence_1, sequence_1_length);
  sort(sequence_2, sequence_2_length);


  std::cout << "Question 4b" << std::endl;

  merge(sequence, sequence_1, sequence_1_length, sequence_2, sequence_2_length);

  std::cout << "Question 4c" << std::endl;

  std::cout << "Please find the solution to Question 4c in the PDF file.\n" << std::endl;

}

void swap(int *left, int *right){ // standard swapping function using pointers as to save memory from declaring new variables for swap

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

      // std::cout << "\nTotal number of iterations: " << iteration_number << "\n" << std::endl; // MARKER: for your interest, I just wanted to know out of curiosity how many iterations it takes

    }


    }

  std::cout << "\n" << std::endl;


}

void merge(int main_array[], int sequence1[], int sequence1_length, int sequence2[], int sequence2_length){

	int i = 0; // counter for sequence 1
	int j = 0; // counter for sequence 2
	int k = 0; // counter for main_array

	while (i < sequence1_length && j < sequence2_length){ // the AND statement is designed to ensure no overflow if one of the sequence is smaller than the other
		if (sequence1[i] < sequence2[j]){
			main_array[k] = sequence1[i];
			i++;
			k++;

		}

		else if (sequence1[i] >= sequence2[j]){
			main_array[k] = sequence2[j];
			j++;
			k++;

		}

	}

	if (i == sequence1_length){ // when sequence 1 is used up; i == sequence1_length rather than i < sequence_length is due to the condition in the if lock, namely tha after each operation i is incremented, thus after the last operation the while loop allows for i, i has been incremented once more before the loop is exited. Hence the current value of i == sequnce1_length (the same would apply in the ase of j if sequence2 causes the end of the while loop)
		for (j; j < sequence2_length; j++){
			main_array[k] = sequence2[j];
			k++;

		}
	}



	else if (j == sequence2_length ){ // when sequence 2 is used up
		for (i; i < sequence1_length; i++){
			main_array[k] = sequence1[i];
			k++;
		}
	}

	std::cout << "The sequence has been sorted. Here is the result: " << std::endl;

	for (int a = 0; a < sequence1_length + sequence2_length; a ++){

		std::cout << main_array[a] << " " << std::flush;
	}

	std::cout << " \n" << std::endl; //start new line after flush

}

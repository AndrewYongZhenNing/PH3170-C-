#include <cmath>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>



int main(){
  // QUESTION 3
  // QUESTION 4a

  // int x = 1;
  // int for_sum = 0;
  // int while_sum = 0;
  //
  // for(int x = 1; x <101; x++){
  //   for_sum += x;
  // }
  // // repeat:
  //
  //
  // while(x <101){
  //   while_sum += x;
  //   x += 1;
  // }
  // std::cout << "The sum from 1 to 100 is: " << while_sum << std::endl;

  // QUESTION 4b - generalising for-while loops
  int n1 = 0;

  int n2 = 0;
  std::string loop_selection;

  start:

    std::cout << "Enter value for n1: ";
    std::cin >> n1;
    std::cout << "\nEnter value for n2: ";
    std::cin>> n2;                          // if n1 > n2, sum goes 0


    if(n1>n2){
      std::cout << "n1 is greater than n2, please select the values such that n1 is less than n2" << std::endl;
      goto start; // jumps back to start of condition again
    }

    loop_type:

      std::cout << "Select the type of loops: for or while?" << std::endl;
      std::cin >> loop_selection;
      // std::getline(std::cin, loop_selection);


      int gen_for_sum = 0;
      int gen_while_sum = 0;

      if(loop_selection == "for"){
        for(n1; n1<n2; n1+= 1){
          gen_for_sum += n1;
        }
        std::cout << " SUM = " << gen_for_sum << std::endl;
      }

      else if(loop_selection == "while"){
        while(n1<n2){

          gen_while_sum += n1;
          n1 +=1;
        }
        std::cout << "SUM = " << gen_while_sum << std::endl;
      }

      else{
        std::cout << "Invalid type of loop, please enter either 'for' or 'while' \n";
        goto loop_type;
      }




  // QUESTION 4d

  // float total = 0;
  // int N = 0;
  // float mean = 0;
  // int negative_values = 0;
  // float maggiore = 0; //largest
  // float minore = 0; // smallest
  // float std_dev = 0;
  // float var_numerator = 0;
  // float store[37];
  //
  //
  // std::string contents;
  // std::ifstream myfile("simpledata.txt");
  //
  // if (myfile.is_open()){
  //
  //
  //   float number;
  //   int i = 0;
  //
  //   while (std::getline(myfile,contents)){
  //
  //     std::stringstream convert(contents);
  //     convert >> number;
  //
  //
  //     store[i] = number;
  //     i += 1;
  //
  //     // store [i] = number;
  //
  //     if (number < 0){ // looks for negative numbers
  //       negative_values += 1;
  //     }
  //
  //     if (number > maggiore){ // looks for largest number
  //       maggiore = number;
  //     }
  //
  //     if (number < minore){
  //       minore = number;
  //     }
  //     // float number = atoi(contents.c_str())
  //
  //     total += number;
  //     N += 1;
  //
  //   }
  //
  //   mean = total/N;
  //
  //   for (int j = 0; j<N; j++){
  //
  //       var_numerator += pow(mean-store[j],2);
  //
  //   }
  //
  //   std_dev = sqrt(var_numerator/N);
  //
  //   myfile.close();
  //
  //   }
  //
  // std::cout << "4di) Sum = " << total << std::endl;
  //
  // std::cout << "\n4dii) Mean =  " << mean << "\t Standard deviation is = " << std_dev <<std::endl;
  //
  // // std::cout << "\nVariance = " << var_numerator/N << std::endl;
  //
  // std::cout << "\n4diii) Number of negative values are = " << negative_values << std::endl;
  //
  // std::cout << "\n4div) Largest value = " << maggiore << "\tSmallest value = " << minore << std::endl;


}

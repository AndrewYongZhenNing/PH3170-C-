#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include "AYONG_PS2Q5.h"

int main(){
  //Question 5

  std::cout << "Question 5" << std::endl;

  int population_mean = 60;
  float sample[60] = {}; // how to do it without specifying array size WITHOUT segmentation fault?
  int length = 0;
  float mean = 0;
  float variance_numerator = 0;
  float standard_deviation = 0;


  std::string samplefile;
  std::ifstream stats("sampledata.txt");

  if (stats.is_open()){

    float number = 0;


    while(std::getline(stats,samplefile)){

      std::stringstream convert(samplefile);
      convert >> number; //convers data in string type to number
      sample[length] = number;
      length ++;

    }
    stats.close();
  }

  // std::cout << sample[2] << std::endl; //sanity check on sample array
  std::cout << length << std::endl;

  for (int i = 0; i < length; i++){ // mean loop
    mean += sample[i];
  }

  mean = mean/length;

  for (int j = 0; j < length; j++){ // variance loop
    variance_numerator += pow(mean-sample[j],2);
  }

  standard_deviation = sqrt(variance_numerator/length);

  t_test(mean,population_mean,length,standard_deviation);

  // WHAT KIND OF HANDLING REQUIRED FOR INCOMING DATA?
  //CONCLUSION
  /*
  Two Sided
  1-(0.05/2) = 0.975
  at Probability = 0.975, and degrees of freedom = 89, the critical value is 1.987
  t test value is 1.683, below critical value, therefore null hypothesis is not rejected

  Upper One Sided
  1-0.05 = 0.95
  Probability = 0.95, and degrees of freedom = 89, the critical value is 1.662
  t test value is 1.683, above critical value, therefore null hypothesis is rejected

  Lower One Sided
  1-0.05 = 0.95
  Probability = 0.95, and degrees of freedom = 89, the critical value is 1.662
  t test value is 1.683, greater than the negative of critical value, therefore null hypothesis is rejected
  */
}

void t_test(float mean, float population_mean, float sample_size, float standard_deviation){

  float output = (mean-population_mean)*sqrt(sample_size)/standard_deviation; // where standard_deviation refers to the sample
  std::cout << "The value of test-statistic, t = " << output << std::endl;
}

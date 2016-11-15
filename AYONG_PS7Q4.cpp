#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

// float mode(vector<float>& sequence);

float meanu(std::vector<float>& v);
float med(std::vector<float>& v);
float modef(std::vector<float>& v);

int main(){

  //calculate MEAN, MODE, MEDIAN, MAX AND MIN

  std::vector<float> liszt;
  std::vector<float>::iterator iter;

  std::vector<float> list;
  std::vector<float>::iterator it;


  float sequence[] = {1,2,5,7.5,8.4,2,6.3,-4.1,-3.2,2,5,14.3,-7.2,8.8,12.2};
  float size = sizeof(sequence)/sizeof(float);

  for (int i =0; i < size; i++){
    liszt.push_back(sequence[i]);
  }

  std::cout << "Consider the following sequence:" << std::endl;

  std::sort(liszt.begin(),liszt.end());

  for (iter = liszt.begin(); iter != liszt.end(); iter++){ // prints the elements of liszt to check if it has all of sequence already
    std::cout << *iter << " "<< std::flush; // *it deferences the iterator pointer, outputting the value in liszt it is pointing at
  }

  std::cout << "\n" << std::endl;

  float max = *std::max_element(liszt.begin(),liszt.end());
  float min = *std::min_element(liszt.begin(),liszt.end());
  float mean = 0;
  float median = 0;
  float mode = liszt[0]; // start it as the first value of liszt


  // CALCULATE MEAN:
  for(iter = liszt.begin(); iter != liszt.end(); iter++ ){

    mean += *iter;

  }

  meanu(liszt);
  mean = mean/liszt.size();

  iter = liszt.begin(); // resets pointer to start in the beginning again

  // CALCULATE MEDIAN

  // std::advance(iter,liszt.size()/2);
  //
  // median = *iter;

  // med(liszt);

  // CALULCATE MODE
  float candidate_mode = 0;

  int mode_frequency = 1;
  int candidate_frequency = 0;

  for(iter = liszt.begin()+1; iter != liszt.end(); iter++) {// resets pointer to start on the second value in liszt

    if (*iter != mode){
      if (*iter != candidate_mode){
        candidate_mode = *iter;
        candidate_frequency =1; // resets to having just one occurrence thus far
      }

      else if (*iter == candidate_mode){
        candidate_frequency ++;
      }

    }

    else if(*iter == mode){
      mode_frequency ++;
    }

    if(candidate_frequency > mode_frequency){
      mode = candidate_mode;
      mode_frequency = candidate_frequency; //transfer the data from candidate to mode
    }

  }

  modef(liszt);

  // REPLACE MODE VALUE WITH 7

  std::replace(liszt.begin(),liszt.end(),mode,7.0f); //7.0f to ensure the number is a float

  float new_mean = 0;
  float new_median = 0;

  std::cout << "Consider the new sequence with 2 replaced by 7:" << std::endl;

  std::sort(liszt.begin(),liszt.end());

  for (iter = liszt.begin(); iter != liszt.end(); iter++){ // prints the elements of liszt to check if it has all of sequence already
    std::cout << *iter << " "<< std::flush; // *it deferences the iterator pointer, outputting the value in liszt it is pointing at
  }

  std::cout << "\n" << std::endl;


  // NEW MEAN

  for(iter = liszt.begin(); iter != liszt.end(); iter++ ){

    new_mean += *iter;

  }

  new_mean = new_mean/liszt.size();

  iter = liszt.begin(); // resets pointer to start in the beginning again



  //NEW MEDIAN
  std::advance(iter,liszt.size()/2);

  new_median = *iter;



  std::cout << "The maximum value is: " << max << std::endl;
  std::cout << "The minimum value is: " << min << std::endl;
  std::cout << "The mean is: " << mean << std::endl;
  std::cout << "The median is: " << median << std::endl;
  std::cout << "The mode is: " << mode << std::endl;
  std::cout << "The new mean is: " << new_mean << std::endl;
  std::cout << "The new median is: " << new_median << std::endl;


}

float modef(std::vector<float>& v){

  std::vector<float>::iterator it;

  float mode = v[0];
  float candidate_mode = 0;

  int mode_frequency = 1;
  int candidate_frequency = 0;

  for(it = v.begin()+1; it != v.end(); it++) {// resets pointer to start on the second value in liszt

    if (*it != mode){
      if (*it != candidate_mode){
        candidate_mode = *it;
        candidate_frequency =1; // resets to having just one occurrence thus far
      }

      else if (*it == candidate_mode){
        candidate_frequency ++;
      }

    }

    else if(*it == mode){
      mode_frequency ++;
    }

    if(candidate_frequency > mode_frequency){
      mode = candidate_mode;
      mode_frequency = candidate_frequency; //transfer the data from candidate to mode
    }

  }

  std::cout << "Mode from function gives: " << mode << std::endl;

  return mode;


}

float meanu(std::vector<float>& v){//


  float mean = 0;
  std::vector<float>::iterator it;
  // it = v.begin();

  for(it = v.begin(); it != v.end(); it++ ){

    mean += *it;

  }

  mean = mean/v.size();

  std::cout << "Function mean is: " << mean << std::endl;

  return mean;

}

float med(std::vector<float>& v){

  std::vector<float>::iterator it;
  float median = 0;
  // std::sort(v.begin(),v.end());

  std::advance(it,v.size()/2);
  median = *it;

  // std::cout << "The median function gives: " << median << std::endl;

  return median;

}

#include "AYONG_PS2Q3.h"
#include <iostream>

int main(){
  // QUESTION 3


  int target_date = 0;
  int target_month = 0;
  int target_year = 0;
  int actual_day = 0;
  // int count = 1;

  std::cout << "Question 3" << std::endl;
  std::cout << "This program finds the day corresponding to the date. \nPlease enter the date, month and year in numerical format." << std::endl;

  start_input:

  std::cout << "Enter date: ";
  std::cin >> target_date;
  std::cout << "Enter month: ";
  std::cin >> target_month;
  std::cout << "Enter year: ";
  std::cin >> target_year;

  switch(target_month){ //switch statement brings program to first of user input month (target_month)
    case 1:
      actual_day = 0;
      break;

    case 2: // February 2000, a leap month, hence 29
      actual_day = 31  ;
      break;

    case 3:
      actual_day = 31 + 29;
      break;

    case 4:
      actual_day = 31 + 29 + 31;
      break;

    case 5:
      actual_day = 31 + 29 + 31 + 30;
      break;

    case 6:
      actual_day = 31 + 29 + 31 + 30 + 31;
      break;

    case 7:
      actual_day = 31 + 29 + 31 + 30 + 31 + 30;
      break;

    case 8:
      actual_day = 31 + 29 + 31 + 30 + 31 + 30 + 31;
      break;

    case 9:
      actual_day = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31;
      break;

    case 10:
      actual_day = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30;
      break;

    case 11:
      actual_day = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31;
      break;

    case 12:
      actual_day = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30;
      break;

  }

  actual_day = (actual_day + (target_date-1))%7; // tells you what day it is of the date and month in 2000

  if (target_month <=2){
    for(int current_year = 2001; current_year < target_year+1; current_year++){ // target_year +1 is such that the target_year itself is also considered



      if((current_year-1)%4 !=0){ //not a leap year

        actual_day += 1;
        // count +=1;
      }

      else if((current_year-1)%4 == 0){ //potential leap year



        if((current_year-1)%100 ==0 and (current_year-1)%400 !=0){ // not a leap year

          actual_day += 1;
          // count +=1;

        }




        // else if( count%400 == 0){ //a leap year
        //
        // actual_day += 2;
        // count +=1;
        //
        // }

        else{ //definitely a leap year

          actual_day +=2;
          // count +=1;

        }
      }


    }
  }

  else if(target_month >2){
    for(int current_year = 2001; current_year < target_year+1; current_year++){ // target_year +1 is such that the target_year itself is also considered



      if((current_year)%4 !=0){ //not a leap year

        actual_day += 1;
        // count +=1;
      }

      else if((current_year)%4 == 0){ //potential leap year



        if((current_year)%100 ==0 and (current_year)%400 !=0){ // not a leap year

          actual_day += 1;
          // count +=1;

        }




        // else if( count%400 == 0){ //a leap year
        //
        // actual_day += 2;
        // count +=1;
        //
        // }

        else{ //definitely a leap year

          actual_day +=2;
          // count +=1;

        }
      }


    }
  }
  // for(int current_year = 2001; current_year < target_year+1; current_year++){ // target_year +1 is such that the target_year itself is also considered
  //
  //
  //
  //   if((current_year-1)%4 !=0){ //not a leap year
  //
  //     actual_day += 1;
  //     // count +=1;
  //   }
  //
  //   else if((current_year-1)%4 == 0){ //potential leap year
  //
  //
  //
  //     if((current_year-1)%100 ==0 and (current_year-1)%400 !=0){ // not a leap year
  //
  //       actual_day += 1;
  //       // count +=1;
  //
  //     }
  //
  //
  //
  //
  /*
      // else if( count%400 == 0){ //a leap year
      //
      // actual_day += 2;
      // count +=1;
      //
      // }
    */
  //
  //     else{ //definitely a leap year
  //
  //       actual_day +=2;
  //       // count +=1;
  //
  //     }
  //   }
  //
  //
  // }

  actual_day = actual_day%7;

  switch(actual_day){
    case 0:
      std::cout << "It's a Saturday!" << std::endl;
      break;

    case 1:
      std::cout << "It's a Sunday!" << std::endl;
      break;

    case 2:
      std::cout << "It's a Monday!" << std::endl;
      break;

    case 3:
      std::cout << "It's a Tuesday!" << std::endl;
      break;

    case 4:
      std::cout << "It's a Wednesday!" << std::endl;
      break;

    case 5:
      std::cout << "It's a Thursday!" << std::endl;
      break;

    case 6:
      std::cout << "It's a Friday!" << std::endl;
      break;

  }

if (target_date == 24 and target_month == 2){
  std::cout << "Happy Birthday, Mr Steve Jobs!" << std::endl; //target_year-1955 <<
}
}

#include <iostream>
// #include "PS4.h"
// #include "PS4f.cpp"

int main(){

  // QUESTION 3

  int M[3][3] = {{5,7,3},{1,8,4},{2,7,6}};

  int determinant = M[0][0]*(M[1][1]*M[2][2] - M[1][2]*M[2][1]) - M[0][1]*(M[1][0]*M[2][2] - M[1][2]*M[2][0]) + M[0][2]*(M[1][0]*M[2][1] - M[1][1]*M[2][0]);

  // int c11 = (M[1][1]*M[2][2] - M[1][2]*M[2][1]);
  // std::cout << "cofactor11 " << c11 << std::endl;
  int cofactor[3][3] = {{(M[1][1]*M[2][2]-M[1][2]*M[2][1]),-(M[1][0]*M[2][2]-M[1][2]*M[2][0]),(M[1][0]*M[2][1] - M[1][1]*M[2][0])},{-(M[0][1]*M[2][2] - M[0][2]*M[2][1]),(M[0][0]*M[2][2] - M[0][2]*M[2][0]),
    -(M[0][0]*M[2][1] - M[0][1]*M[2][0])},{(M[0][1]*M[1][2] - M[0][2]*M[1][1]),-(M[0][0]*M[1][2] - M[0][2]*M[1][0]),(M[0][0]*M[1][1] - M[0][1]*M[1][0])}};

  int t_cofactor[3][3] = {};

  int identity[3][3] = {};

  // std::cout << "before" << cofactor[0][2] << std::endl;

  for (int i = 0; i < 3; i++){ //iterate through every row

    for (int j = 0; j < 3; j++){ //iterate through every column

      t_cofactor[i][j] = cofactor[j][i]; //transpose successful

      std::cout << "cofactor transposed"<< t_cofactor[i][j] << std::endl;

    }
  }

  // std::cout << "after" << t_cofactor[2][0] << std::endl;

  for (int i = 0; i < 3; i++){ // i is row iteration

    for (int j = 0; j < 3; j++){ // j is column iteration

      int I = 0;
      for(int k = 0; k < 3; k++){ //k is iteration through row/column of each matrix's element

        I += M[i][k]*t_cofactor[k][j];//*1./determinant; //using determinant here will give results close to identity matrix, except first time is equals to -2, why?!
        // identity[i][j] += M[i][k]*t_cofactor[k][j]/determinant; // i suspect using += on arrays is not good practice


        // std::cout << "i:" << i << " j:" << j << " k:" << k << "\t" << result << std::endl;

      }
      identity[i][j] = I/determinant; // this is where the matrix multiplication between M and M_inverse completes, an identity matrix is found
      std::cout << identity[i][j] << std::endl;

    }
  }

  for(int i = 0; i <3; i++){
    for (int j =0; j < 3; j++){

        // std::cout << identity[i][j] << std::endl;

      if (j==2){
        std::cout << "\n" << std::endl;

      }
    }
  }
  // int test = M[0][0]*t_cofactor[0][0]*1./determinant+ M[0][1]*t_cofactor[1][0]*1./determinant + M[0][2]*t_cofactor[2][0]*1./determinant;
  //
  // std::cout << test << std::endl;
  // std::cout << "1st term:"<<identity[0][0] << std::endl;


}
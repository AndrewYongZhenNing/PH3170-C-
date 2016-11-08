#include "4vector.h"
#include "4vector.cpp"

#include <cmath>
#include <cstdlib>
#include <ctime> // such that the randomiser depends on computer time
#include <random>
// #include <iostream>
// #include <random>
//
// void gaussian(double mean, double sigma){
//   std::default_random_engine random;
//   std::normal_distribution<double> distribution(mean,sigma);
//
//   for(int count = 0; count < 50; count++){
//     std::cout << distribution(random) << std::endl;
//   }
// }


int main(){

  srand(time(NULL)); // set the initialised random value here in main, rather than do it every time because each time it is called it will be re-initialised again so the random seed never changes and thus will produce the same value again 




  /*std::default_random_engine generator;
  std::normal_distribution<double> distribution(5.0,2.0);

  for(int i=0;i<100;i++){
    std::cout<<distribution(generator)<<std::endl;
  }

}*/

  // gaussian(15,2);
  // //
  // double mass = 30.0;
  // double mass_distribution[1000] = {0};
  //
  // for (int i =0; i < 1000; i ++){
  //  mass_distribution[i] = 30; // mass*rand()/RAND_MAX gives random masses
  //  std::cout << mass_distribution[i] << std::endl;
  // }

  double Detected_mass = 0;

  //vectors

  std::vector<SimulatedParticle> particles;

  for(int i =0; i < 1000; i++){
    SimulatedParticle p(30.0);
    particles.push_back(p);
    DetectedParticle dp(p);
    // dp.Gaussian();

    Detected_mass += dp.getInvariant();
  }

  Detected_mass = Detected_mass/1000;

  std::cout << "average " << Detected_mass << std::endl;

  // SimulatedParticle tryon(3.0);
  // tryon.getInvariant();

  SimulatedParticle p1(25.0);
  // SimulatedParticle p2(25.0);
  // p.getInvariant();

  DetectedParticle dp1(p1);
  // DetectedParticle dp2(p2);
  // dp1.Gaussian();
  // dp2.Gaussian();
  dp1.getInvariant();
  // dp2.getInvariant();
  // double test2 = dp2.Gaussian();
  // std::cout << test1 << " " << test2 << std::endl;
  // dp.Gaussian()


}

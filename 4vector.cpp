#include "4vector.h"

// BASE CLASS: 4 VECTOR

Four_Vector::Four_Vector(double t, double x, double y, double z): _t(t), _x(x), _y(y), _z(z){
  pi = 4*atan(1);
}

Four_Vector::~Four_Vector(){};

double Four_Vector::getInvariant(){

  double mass_squared = pow(_t,2) - pow(_x,2) - pow(_y,2) - pow(_z,2);

  std::cout << "The interval is: " << sqrt(mass_squared) << std::endl;

  return sqrt(mass_squared);

}

SimulatedParticle::SimulatedParticle(double mass):Four_Vector(0,0,0,0){
  _mass = mass;
  _momentum = 100;

  //GETS RANDOM MOMENTUM HERE:
  double momentum_magnitude = triangular(_momentum); // can i use triangular here when it is defined below (after the constructor)?

  //SPLITS RANDOM MOMENTUM INTO COMPONENTS: INTRODUCE RANDOMISED ANGULAR PARAMETERS:
  

  double polar = pi*rand()/RAND_MAX; // gets a random value between 0 and pi
  double azimuthal = 2*pi*rand()/RAND_MAX; // gets a random value between 0 and 2pi


  _x = momentum_magnitude*sin(polar)*cos(azimuthal); // momenta components
  _y = momentum_magnitude*sin(polar)*sin(azimuthal);
  _z = momentum_magnitude*cos(polar);


  std::cout << "\nSimulated particle: \nMomentum magnitude: " << momentum_magnitude << "\npx: " << _x <<  "\npy: " << _y << "\npz: " << _z << std::endl;

  _t = sqrt(pow(mass,2)+pow(momentum_magnitude,2)); //returns energy as a data member

}

double SimulatedParticle::getInvariant(){

  double mass_squared = pow(_t,2) - pow(_x,2) - pow(_y,2) - pow(_z,2);

  std::cout << "The invariant mass is: " << sqrt(mass_squared) << std::endl;

  return sqrt(mass_squared);

}

double SimulatedParticle::triangular(double momentum){

  double random_momentum, tolerance;

  do{
    random_momentum = momentum*rand()/RAND_MAX;
    tolerance = random_momentum/momentum; // this is basically ensuring that random_momentum is not less than 1(?)
  } while (1*rand()/RAND_MAX > tolerance);

  return random_momentum;

}


DetectedParticle::DetectedParticle(SimulatedParticle(mass)):SimulatedParticle(mass){ //

  std::cout << "\nIn the detector, the momenta are, px: " << _x << " _py: " << _y << " pz: " << _z << std::endl;
  std::cout << "In the detector, the mass is: " << _mass  << std::endl;

  Gaussian();

}

void DetectedParticle::Gaussian(){

  // double energy_distribution[1000] = {0};
  // double energy_sum = 0;

  std::cout << "\nEnergy: before: " << _t << std::endl;
  double sigma = 0.14*sqrt(_t);
  std::default_random_engine random_energy;
  std::normal_distribution<double> distribution(_t,sigma);

  _t = distribution(random_energy);

  std::cout << "Energy: after: " << _t << std::endl;

  // for (int count =0; count < 1000; count++){
  //   energy_distribution[count] = distribution(random_energy);
  //   energy_sum += energy_distribution[count];
  //   std::cout <<"Smeared energy: " << energy_distribution[count] << "\tenergy sum: " << energy_sum<< std::endl;
  //   _t = energy_sum/1000;
  // }


  // return distribution(random_energy); // returns smeared energy
}

double DetectedParticle::getInvariant(){

  double mass_squared = pow(_t,2) - pow(_x,2) - pow(_y,2) - pow(_z,2);

  std::cout << "The invariant mass is: " << sqrt(mass_squared) << std::endl;

  return mass_squared;

}
// VIRTUAL FUNCTIONS

//
// double Invariant(Four_Vector &four_quantity){
//   std::cout << "The invariant quantity is: " << four_quantity.getInvariant() << std::endl;
//   return four_quantity.getInvariant();
// }

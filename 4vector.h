#ifndef _4VECTOR
#define _4VECTOR
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime> // such that the randomiser depends on computer time
#include <random> // requires flag at compilation via terminal: -std=c++11
#include <vector>


// BASE CLASS : Four_Vector
class Four_Vector{

public:

  Four_Vector(double t, double x, double y, double z); //try with array on heap later

  ~Four_Vector();

  double getInvariant(); // can maybe make this virtual since 4-momentum needs it?

protected:

  double pi;

  double _t; //here one uses natural units, c = 1
  double _x;
  double _y;
  double _z;

};

//DERIVED CLASS: SIMULATEDPARTICLE

class SimulatedParticle:public Four_Vector{

public:

  SimulatedParticle(double mass);

  double getInvariant();
  double triangular(double momentum);


protected:

  double _momentum;
  double _mass;

};

// DERIVED CLASS (SIMULATED PARTICLE): DETECTEDPARTICLE

class DetectedParticle: public  SimulatedParticle{

public:

  DetectedParticle(SimulatedParticle(mass));

  void Gaussian();
  double getInvariant();

private:

  double mean; // equivalent to the unsmeared energy
  double width; //
};

#endif

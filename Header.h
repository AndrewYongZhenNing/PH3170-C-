#ifndef _KLASS_
#define _KLASS_


class Measurement{
public:
	Measurement(double meas, double error);
	Measurement();
	~Measurement();

	double FractionalError();
	void Add(const Measurement &rhs);
	void Print();

	Measurement Measurement::operator+(const Measurement &rhs);
	Measurement Measurement::operator+(int a);
	Measurement Measurement::operator=(const Measurement &rhs);
	Measurement Measurement::operator-(const Measurement &rhs);
	Measurement Measurement::operator*(const Measurement &rhs);
	Measurement Measurement::operator/(const Measurement &rhs);

private:
	double _meas;
	double _error;
};

#endif 
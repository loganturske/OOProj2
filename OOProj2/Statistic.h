#pragma once
#include <vector>

class Statistic
{
public:
	/*
		Constructor
	*/
	explicit Statistic();

	/*
		This method will add the paramerte x (double) to the local vector (vec)
	*/
	void add(double x);

	/*
		This method will return (double) the average of the local vector (vec)
	*/
	double average() const;

	/*
		This method will return (double) the standard deviation of the local vector (vec)
	*/
	double STD() const;

private:
	// Vector from the standard library
	std::vector<double> vec;
};


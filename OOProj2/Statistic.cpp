#include "Statistic.h"
#include <math.h>

Statistic::Statistic()
	: vec() {};


void Statistic::add(double x)
{
	this->vec.push_back(x);
};


double Statistic::average() const
{
	// Keep a running total
	double runningTotal = 0;

	// For each double in the vector, add it to the runningTotal
	for (double n : this->vec)
	{
		runningTotal += n;
	}

	// Return the runningTotal divided by the size of the vector
	return runningTotal / this->vec.size();
};


double Statistic::STD() const
{
	// Get the mean (average)
	double mean = this->average();

	// Keep a running total for when you iterate over the vector (vec) to get the variance
	double variance = 0;

	// For each number in the vector (vec), subtrace the mean and square the result and add it to the runningTotal
	for (double n : this->vec)
	{
		variance += (n - mean) * (n - mean);
	}

	// To complete the variance you must divide the running total by the number of numbers in the vector (vec)
	variance /= this->vec.size() - 1;

	// Return the result of the square root of the vairance
	return (double)sqrt(variance);

};

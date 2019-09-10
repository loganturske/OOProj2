// OOProj2.cpp
// This will be the main file for building and testing the classes
// 
// Author: Logan Turske

#include <iostream>
#include <list>
#include <fstream>
#include <string>

#include "Statistic.h"

using namespace std;

/*
	This method is for comparing doubles due to the error prone arithmetic
*/
bool doubleEquals(double a, double b, double epsilon = 0.001)
{
	return abs(a - b) < epsilon;
}

/*
	This method is for testing the Statistic class and getting the average
*/
bool TestAverage(list<double> nums, double ans)
{
	try {
		Statistic stat = Statistic();
		for (double n : nums) {
			stat.add(n);
		}

		if (doubleEquals(stat.average(), ans))	return true;

		cout << "Error: Could not compute correct Average" << endl;
		cout << "\tCalculated: " << stat.average() << " Answer: " << ans << endl;
		return false;
	}
	catch (exception e) {
		cout << "Error: Statistic constructor threw an exception" << endl;
		return false;
	}

}

/*
	This method is for testing the Statisitic class and getting the standard deviation
*/
bool TestSTD(list<double> nums, double ans)
{
	try {
		Statistic stat = Statistic();
		for (double n : nums) {
			stat.add(n);
		}

		if (doubleEquals(stat.STD(), ans))	return true;

		cout << "Error: Could not compute correct Standard Deviation" << endl;
		cout << "\tCalculated: " << stat.STD() << " Answer: " << ans << endl;
		return false;
	}
	catch (exception e) {
		cout << "Error: Statistic constructor threw an exception" << endl;
		return false;
	}
}

/*
	This method will read a file line by line and put it into a list of doubles
*/
list<double> getNumbersFromFile(string filePath)
{
	list<double> retList;
	ifstream file(filePath);
	string str;
	
	while (getline(file, str))
	{
		retList.push_front(stod(str));
	}

	return retList;
}

/*
	Main
*/
int main()
{
	list<double> testList = { 9, 2, 5, 4, 12, 7, 8, 11, 9, 3, 7, 4, 12, 5, 4, 10, 9, 6, 9, 4 };
	double avg = 7;
	double std = 3.06079;

	list<double> fromFile = getNumbersFromFile("C:\\Users\\Logan\\Documents\\random.txt");
	double fileAvg = 216.735;
	double fileStd = 187.73;

	cout << "Begin Tests." << endl;

	TestAverage(testList, avg);
	TestSTD(testList, std);

	TestAverage(fromFile, fileAvg);
	TestSTD(fromFile, fileStd);

	cout << "End Tests." << endl;

}
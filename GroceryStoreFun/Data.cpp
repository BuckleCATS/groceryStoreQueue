/*
	Programmer: Kaitlyn Hornbuckle
			Class: CPT 122, Spring 2021; Lab Section 6
			Date: March 15, 2021
			Description: The program simulates a grocery store!
*/


#include "Data.h"

Data::Data()
{
	customerNumber = 1;
	totalTime = 0;
	serviceTime = 0; //random time

}

//copy constructor
Data::Data(const Data& ptr)
{

}

//deconstructor
Data::~Data()
{

}

//getters
int Data::getCustomerNumber()
{
	return customerNumber;
}

int Data::getServiceTime()
{
	return serviceTime;
}

int Data::getTotalTime()
{
	return totalTime;
}

//setters
void Data::setCustomerNumber(int number)
{
	customerNumber = number;
}

void Data::setServiceTime(int number)
{
	serviceTime = number;
}

void Data::setTotalTime(int number)
{
	totalTime = number;
}




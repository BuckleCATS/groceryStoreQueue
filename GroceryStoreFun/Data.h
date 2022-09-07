/*
	Programmer: Kaitlyn Hornbuckle
			Class: CPT 122, Spring 2021; Lab Section 6
			Date: March 15, 2021
			Description: The program simulates a grocery store!
*/
#ifndef DATA
#define DATA

#include <iostream>

class Data
{
public:
	//constructor
	Data();

	//copy constructor
	Data(const Data& ptr);

	//deconstructor
	~Data();

	//getters
	int getCustomerNumber();
	int getServiceTime();
	int getTotalTime();

	//setters
	void setCustomerNumber(int number);
	void setServiceTime(int number);
	void setTotalTime(int number);

private:
	int customerNumber;
	int serviceTime; //random time
	int totalTime; 
	//don't forget to allocate this memory on the heap!
};

#endif

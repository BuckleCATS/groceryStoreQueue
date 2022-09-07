/*
	Programmer: Kaitlyn Hornbuckle
			Class: CPT 122, Spring 2021; Lab Section 6
			Date: March 15, 2021
			Description: The program simulates a grocery store!
*/

#include "Queue.h"
#include "Test.h"

//constructor
Queue::Queue() 
{
	pHead = nullptr;
	pTail = nullptr;
}

//destructor
Queue::~Queue()
{
	
}

void Queue::runProgram()
{
	test access;
	access.test_run();
}
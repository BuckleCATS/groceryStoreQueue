/*
	Programmer: Kaitlyn Hornbuckle
			Class: CPT 122, Spring 2021; Lab Section 6
			Date: March 15, 2021
			Description: The program simulates a grocery store!
*/

#ifndef QUEUE
#define QUEUE

#include <iostream>
#include "QueueNode.h"

class Queue
{
public:
	//constructor
	Queue();

	//destructor
	~Queue();

	//members
	void runProgram();

private:
	QueueNode* pHead;
	QueueNode* pTail;
};



#endif

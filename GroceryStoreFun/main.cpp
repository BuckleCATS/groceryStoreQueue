/*
	Programmer: Kaitlyn Hornbuckle
			Class: CPT 122, Spring 2021; Lab Section 6
			Date: March 15, 2021
			Description: The program simulates a grocery store!
*/

#include <iostream>
#include "Test.h"
#include "Queue.h"

int main()
{

	/*************************************************************/
	//THESE ARE OUR TEST CASES:
	//Feel free to uncomment each one to use them!
	test access;
	Queue mainAccess;
	//1. Executes enqueue() on an empty queue
	//access.enqueueOnEmptyQueue();
	//2. Executes enqueue() on a queue with one node
	//access.enqueueWithOneNode();
	//3. Executes dequeue() on a queue with one node
	//access.dequeueWithOneNode();
	//4. Executes dequeue() on a queue with two nodes
	//access.dequeueWithTwoNodes(); 
	//5. Runs the simulation for 24 hours
	srand(time(NULL)); //Help from TA Nathan Brown to fix random numbers generation problem (NOTE TO SELF: srand(NULL) must be called once, not multiple times. I wonder why this is the case?)
	//access.test_run();
	/*************************************************************/

	mainAccess.runProgram();
}
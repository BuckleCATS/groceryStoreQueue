/*
	Programmer: Kaitlyn Hornbuckle
			Class: CPT 122, Spring 2021; Lab Section 6
			Date: March 15, 2021
			Description: The program simulates a grocery store!
*/
#ifndef TEST
#define TEST

#include <iostream>
#include <time.h>


class test
{
public:
	//constructor
	test();

	//copy constructor
	test(test* node);

	//deconstructor
	~test();

	//getters
	int getCustomerNumber();
	int getServiceTime();
	int getTotalTime();

	//setters
	void setCustomerNumber(int number);
	void setServiceTime(int number);
	void setTotalTime(int number);

	//queue functions
	test* enqueue(test* node);
	void printQueue(test* queue);
	bool isEmpty();
	test* dequeue();

	//print functions
	int ExpressArrival();
	int NormalArrival();
	int ExpressService();
	int NormalService();


	// TEST CASES
	//1. Executes enqueue() on an empty queue
	void enqueueOnEmptyQueue();
	//2. Executes enqueue() on a queue with one node
	void enqueueWithOneNode();
	//3. Executes dequeue() on a queue with one node
	void dequeueWithOneNode();
	//4. Executes dequeue() on a queue with two nodes
	void dequeueWithTwoNodes();
	//5. Runs the simulation for 24 hours
	void test_run();

private:
	int customerNumber;
	int serviceTime;
	int totalTime;

	test* head;
	test* pNext;
};

#endif
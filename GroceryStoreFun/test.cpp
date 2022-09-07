/*
	Programmer: Kaitlyn Hornbuckle
			Class: CPT 122, Spring 2021; Lab Section 6
			Date: March 15, 2021
			Description: The program simulates a grocery store!
*/


#include "Test.h"

//THESE ARE FOR OUR TEST FUNCTIONS! :)
//constructor
test::test()
{
	customerNumber = 1;
	totalTime = 0;
	serviceTime = 0; //random time
}

//copy constructor
test::test(test* node)
{
	if (node->customerNumber == 0)
	{
		node->customerNumber = customerNumber;
		node->totalTime = totalTime;
		node->serviceTime = serviceTime;
	}

}

//deconstructor
test::~test()
{
	//Only deletes one node every time the destructor is called!
	this->head = nullptr;
	delete head;

	
}

//getters
int test::getCustomerNumber()
{
	return customerNumber;
}

int test::getServiceTime()
{
	return serviceTime;
}

int test::getTotalTime()
{
	return totalTime;
}

//setters
void test::setCustomerNumber(int number)
{
	customerNumber = number;
}

void test::setServiceTime(int number)
{
	serviceTime = number;
}

void test::setTotalTime(int number)
{
	totalTime = number;
}

//enqueue
test* test::enqueue(test* node)
{
	/*
	//for first customer
	if (this->pNext == nullptr && this->customerNumber == 1)
	{
		head = new test(*this);
	}
	//for the second customer
	if (this->pNext == nullptr && this->customerNumber == 2)
	{
		//head = head->pNext; //moves head to beginning of the queue
		head->pNext = new test(*this);
	}
	if (head == nullptr)
	{
		head = new test(*this);
	}
	//for any customers greater than 2
	else
	{
		test* ptr;
		ptr = new test(*head);

		while (head->pNext != nullptr)
		{
			head = head->pNext;

		}


		head->pNext = new test(*this);
		head = new test(*ptr);
	}
	*/

	//for first customer
	if (node->head == nullptr || node->customerNumber == -1)
	{
		node->head = new test(*this);
	}
	else
	{
		test* ptr = nullptr;

		ptr = new test(*node->head);

		while (node->head->pNext != nullptr)
		{
			head = node->head->pNext;
		}

		ptr->pNext = new test(*this);
		ptr->pNext->head = nullptr;
		head = new test(*ptr);
		

	}

	return head;
}

void test::printQueue(test* queue)
{
	if (queue->head != nullptr)
	{
		std::cout << "The queue is empty!" << std::endl;
	}
	/*
	while (queue->head != nullptr)
	{
			test* ptr;
			ptr = new test(queue->head);

			while (queue->head->pNext != nullptr)
			{
				std::cout << "Customer # still in the queue: " << queue->head->customerNumber << std::endl;
				queue = queue->head->pNext;
			}
			if (queue->head->pNext == nullptr)
			{
				std::cout << "Customer # still in the queue: " << queue->head->customerNumber << std::endl;
			}

			queue->head = new test(*ptr);
			queue = queue->head;
	}
	*/
	if (queue->pNext != nullptr)
	{
		//if (queue->customerNumber != queue->pNext->customerNumber)
		//{

		//	std::cout << "Customer # still in the queue: " << queue->customerNumber << std::endl;
		//}
		while (queue->pNext != nullptr)
		{
			
			std::cout << "Customer # still in the queue: " << queue->pNext->customerNumber << std::endl;
			queue = queue->pNext;
		}
	}

}

//Checks if the list is empty!
bool test::isEmpty()
{
	if (head->totalTime == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

test* test::dequeue()
{
	if (isEmpty() == false)
	{
		test* ptr = nullptr;

		//this is when there is just one node
		if (head->pNext == NULL)
		{
			
			delete head;
			//restarts the queue
			head->head = nullptr;
			head->pNext = nullptr;
			head->customerNumber = -1;
			head->serviceTime = 0;
			head->totalTime = 0;
			
		}
		//this is when there are more than two nodes
		else
		{
			head = head->pNext;

			/*
			if (head->customerNumber == head->pNext->customerNumber)
			{
				head->pNext = nullptr;
			}
			*/

			head->head = nullptr; //fixes doubly linked list mistake, lol
		}
	
		std::cout << "Congratulations! You have dequeued one node." << std::endl;
	}
	else
	{
		std::cout << "List is empty. There is nothing to dequeue!" << std::endl;
	}

	return head;
}

// THE FIVE TEST CASES
//1. Executes enqueue() on an empty queue
void test::enqueueOnEmptyQueue()
{
	test ptr;
	enqueue(&ptr);
	printQueue(&ptr);
}

//2. Executes enqueue() on a queue with one node
//PRECONDITION: only works if enqueueOnEmptyQueue() is called first
void test::enqueueWithOneNode()
{
	//Create node #1
	setCustomerNumber(1);
	setServiceTime(4);
	setTotalTime(10);

	test tempPtr;
	enqueue(&tempPtr);
	printQueue(&tempPtr);

	//Uncomment code below to test more than one node
	
	//Create node #2
	
	setCustomerNumber(2);
	setServiceTime(15);
	setTotalTime(30);

	enqueue(&tempPtr);
	printQueue(&tempPtr);
	
	
	//Create node #3
	/*
	setCustomerNumber(3);
	setServiceTime(30);
	setTotalTime(45);

	enqueue(&tempPtr);
	printQueue();
	*/
	
}

//3. Executes dequeue() on a queue with one node
void test::dequeueWithOneNode()
{
	if (isEmpty() == false)
	{
		test* ptr;

		while (head->pNext != NULL)
		{
			head = head->pNext;

		}

		ptr = new test(*head->head);
		ptr->pNext = nullptr;
		//delete head;
		head = new test(*ptr);
		printQueue(ptr);


		std::cout << "Congratulations! You have dequeued one node." << std::endl;
	}
	else
	{
		std::cout << "List is empty. There is nothing to dequeue!" << std::endl;
	}
}

//4. Executes dequeue() on a queue with two nodes
//PRECONDITION: UNCOMMENT THE COMMENT BLOCK THAT CREATES THE SECOND NODE IN THE ENQUEUEWITHONENODE() BEFORE USING
void test::dequeueWithTwoNodes()
{
	dequeueWithOneNode(); //only dequeues one node per call!
	std::cout << "Remaining node: " << head->totalTime << std::endl; //this only works when there a max of 2 nodes in the queue
}

//5. Runs the simulation for 24 hours
void test::test_run()
{
	//These are our two queues!
	test expressLane;
	test normalLane;
	int timeVar = 0;

	std::cout << "Welcome to CatMart." << std::endl;
	std::cout << "\n" << std::endl;
	std::cout << "We are generating people for you..." << std::endl;

	int minutes;
	std::cout << "How long would you like to run this simulation for?" << std::endl;
	std::cin >> minutes;

	int expressLaneArrival = 0;
	int normalLaneArrival = 0;
	int expressService = 0;
	int normalService = 0;
	int processTime = 0;
	int endTime = 0;
	int cats = 0; //trigger for stuck at register
	int dogs = 0;//trigger for waiting in line
	int stuck = 0;

	while (timeVar != minutes)
	{
		//Initializes the first arrival time for each lane
		if (timeVar == 0)
		{
			//Generates arrival times for Express Lane
			expressLaneArrival = ExpressArrival();
			
			//Generates arrival times for Normal Lane
			normalLaneArrival = NormalArrival();
			
			
		}
		
		
		if (timeVar == expressLaneArrival)
		{
			//Generates service times for Express Lane
			expressService = ExpressService();

			//Generates arrival time of new customer
			expressLaneArrival = ExpressArrival();
			processTime = timeVar + expressLaneArrival;
			expressLaneArrival = processTime;

			if (customerNumber != stuck)
			{
					std::cout << "Customer #" << customerNumber << " is waiting in line in the express lane!" << std::endl;
					//Processes Customer Data from Express Lane and inserts into queue
					expressLane.setCustomerNumber(customerNumber);
					expressLane.setServiceTime(expressService);
					expressLane.setTotalTime(expressService + expressLaneArrival);
					expressLane.head = expressLane.enqueue(&expressLane);

					++dogs;
			
			}
			/*
			if (customerNumber == 1)
			{
				std::cout << "Customer #" << customerNumber << " is waiting in line in the express lane!" << std::endl;
				//Processes Customer Data from Express Lane and inserts into queue
				expressLane.setCustomerNumber(customerNumber);
				expressLane.setServiceTime(expressService);
				expressLane.setTotalTime(expressService + expressLaneArrival);
				expressLane.head = expressLane.enqueue(&expressLane);
				//printQueue();

				std::cout << "Customer #" << customerNumber << " is at the cash register in the express lane!" << std::endl;
				endTime = timeVar + expressService;
				stuck = customerNumber;

				cats = 1;
			}
			*/
			if (cats == 0)
			{
				if (customerNumber != 1)
				{
					std::cout << "Customer #" << customerNumber << " is at the cash register in the express lane!" << std::endl;
					endTime = timeVar + expressService;
					stuck = customerNumber;

					cats = 1;
				}
				else
				{
					
						std::cout << "Customer #" << customerNumber << " is at the cash register in the express lane!" << std::endl;
						endTime = timeVar + expressService;
						stuck = customerNumber;

						cats = 1;
					
				}
			}

				++customerNumber;
			
			
			
		}

		if (endTime > 0)
		{
			//Tracks what customer is exiting the queue
			if (endTime == timeVar)
			{
				std::cout << "Customer #" << stuck << " has checked out of the express lane!" << std::endl;
				customerNumber = stuck + 1;
				expressLane.head = expressLane.dequeue();
				cats = 0;
			}
		}
		


		
		if (timeVar == normalLaneArrival)
		{
			//Generates service times for Express Lane
			normalService = NormalService();

			//Generates arrival time of new customer
			normalLaneArrival = NormalArrival();
			processTime = timeVar + normalLaneArrival;
			normalLaneArrival = processTime;

			if (customerNumber != stuck)
			{
				std::cout << "Customer #" << customerNumber << " is waiting in line in the normal lane!" << std::endl;
				//Processes Customer Data from Express Lane and inserts into queue
				normalLane.setCustomerNumber(customerNumber);
				normalLane.setServiceTime(normalService);
				normalLane.setTotalTime(normalService + normalLaneArrival);
				normalLane.head = normalLane.enqueue(&normalLane);

				++dogs;

			}
			/*
			if (customerNumber == 1)
			{
				std::cout << "Customer #" << customerNumber << " is waiting in line in the express lane!" << std::endl;
				//Processes Customer Data from Express Lane and inserts into queue
				expressLane.setCustomerNumber(customerNumber);
				expressLane.setServiceTime(expressService);
				expressLane.setTotalTime(expressService + expressLaneArrival);
				expressLane.head = expressLane.enqueue(&expressLane);
				//printQueue();

				std::cout << "Customer #" << customerNumber << " is at the cash register in the express lane!" << std::endl;
				endTime = timeVar + expressService;
				stuck = customerNumber;

				cats = 1;
			}
			*/
			if (cats == 0)
			{
				if (customerNumber != 1)
				{
					std::cout << "Customer #" << customerNumber << " is at the cash register in the normal lane!" << std::endl;
					endTime = timeVar + expressService;
					stuck = customerNumber;

					cats = 1;
				}
				else
				{

					std::cout << "Customer #" << customerNumber << " is at the cash register in the normal lane!" << std::endl;
					endTime = timeVar + expressService;
					stuck = customerNumber;

					cats = 1;

				}
			}

			++customerNumber;



		}

		if (endTime > 0)
		{
			//Tracks what customer is exiting the queue
			if (endTime == timeVar)
			{
				std::cout << "Customer #" << stuck << " has checked out of the normal lane!" << std::endl;
				customerNumber = stuck + 1;
				normalLane.head = normalLane.dequeue();
				cats = 0;
			}
		}
		
		
	//Finish printing entire queue out every 10 minutes
		if (timeVar % 10 == 0 && timeVar != 0)
		{
			std::cout << "***************************************" << std::endl;
			std::cout << "Minute 10 Express Queue Report: " << std::endl;
			
			/*
			while (expressLane.head->pNext != nullptr)
			{
				std::cout << expressLane.head->customerNumber << ", ";
				expressLane = expressLane.head->pNext;
			}
			*/
			
			printQueue(expressLane.head);
			std::cout << "***************************************" << std::endl;
			std::cout << "Minute 10 Normal Queue Report: " << std::endl;
			printQueue(normalLane.head);
			std::cout << "***************************************" << std::endl;
		}

		++timeVar;
	}
	
}

int test::ExpressArrival()
{
	//Generates arrival times for Express Lane
	int expressLaneArrival = 1;
	expressLaneArrival = rand() % 5 + 1;
	//std::cout << "Arrival Time of First Customer in Express Lane: " << expressLaneArrival << std::endl;
	return expressLaneArrival;
}

int test::NormalArrival()
{
	int normalLaneArrival = 1;

	normalLaneArrival = rand() % 8 + 3;

	if (normalLaneArrival > 8) //temp fix for generating 10 problem
	{
		while (normalLaneArrival > 8)
		{
			normalLaneArrival = rand() % 8 + 3;
		}
	}
	//std::cout << "Arrival Time of First Customer in Normal Lane: " << normalLaneArrival << std::endl;
	return normalLaneArrival;
}

int test::ExpressService()
{
	int expressLaneService = 1;

	expressLaneService = rand() % 5 + 1;
	//std::cout << "Service Time of First Customer in Express Lane: " << expressLaneService << std::endl;

	return expressLaneService;
}

int test::NormalService()
{
	int normalLaneService = 1;

	normalLaneService = rand() % 8 + 3;

	if (normalLaneService > 8) //temp fix for generating 10 problem
	{
		while (normalLaneService > 8)
		{
			normalLaneService = rand() % 8 + 3;
		}
	}
	//std::cout << "Service Time of First Customer in Normal Lane: " << normalLaneService << std::endl;

	return normalLaneService;
	
}
/*
	Programmer: Kaitlyn Hornbuckle
			Class: CPT 122, Spring 2021; Lab Section 6
			Date: March 15, 2021
			Description: The program simulates a grocery store!
*/

#include "QueueNode.h"
#include "Test.h"
//enqueue
//QueueNode* QueueNode::enqueue(QueueNode* node)
//{
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
	/*
	if (node->pTail == nullptr || pData == -1)
	{
		node->pTail = new QueueNode(*this);
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
	/*
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
	//if (queue->pNext != nullptr)
	//{
		//if (queue->customerNumber != queue->pNext->customerNumber)
		//{

		//	std::cout << "Customer # still in the queue: " << queue->customerNumber << std::endl;
		//}
		//while (queue->pNext != nullptr)
		//{

			//std::cout << "Customer # still in the queue: " << queue->pNext->customerNumber << std::endl;
			//queue = queue->pNext;
		//}
	//}

//}

//Checks if the list is empty!
/*
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
*/
/*
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
*/
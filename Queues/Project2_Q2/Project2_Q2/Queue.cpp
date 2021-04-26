/*Author: Maitra Patel
* Date Created: 3/10/2018
* Date Modified: 3/18/2018
* Purpose: Create a Queue of type string using linked list, and also have a copy constructer to copy one queue to another.
*/
#include <iostream>
#include <string>
using namespace std;
#include "Queue.h"

//Constructer
Queue::Queue()
{
	front = NULL;
	rear = NULL;
}
//Copy Constructer
//Pre-Condtion: A queue to copy from
//Post-Condition: Queue is copied to this queue
Queue::Queue(const Queue &x)
{
	//Make sure this queue is empty..
	front = NULL;
	rear = NULL;

	NodeType *tempPtr = x.front;
	if (tempPtr == NULL)
	{
		front = NULL;
		rear = NULL;
	}
	else
	{
		while (tempPtr != NULL)
		{
			Enqueue(tempPtr->info);
			tempPtr = tempPtr->next;
		}
	}
}
//Make Empty Function
//Post-Condition: Empties the queue
void Queue::MakeEmpty()
{
	string x = "0";
	while ((front != NULL) && (rear != NULL))
	{
		Dequeue();
	}
}
//IsEmpty function
//Post Condition: Returns if the function is empty or not
bool Queue::IsEmpty()
{
	return ((rear == NULL) && (front == NULL));
}
//IsFull function
//Post Condition: Returns if the function is full or not
bool Queue::IsFull()
{
	return(length() == 100);
}
//Enqueue function
//Post Condition: Adds a node to the end of queue
void Queue::Enqueue(string x)
{
	NodeType *newNode = new NodeType;
	newNode->info = x;
	newNode->next = NULL;

	if (IsEmpty())
	{
		front = newNode;
		rear = newNode;
	}
	else
	{
		NodeType *currPtr = front;
		while (currPtr->next != NULL)
		{
			currPtr = currPtr->next;
		}
		currPtr->next = newNode;
		rear = newNode;
	}
}
//Dequeue function
//Post Condition: Removes a node from the front of the queue
void Queue::Dequeue()
{
	NodeType *location;
	if (IsEmpty())
	{
		cout << "Error: Cannot Dequeue, Queue is already Empty." << endl;
	}
	else
	{
		location = front;
		if (front->next == NULL)
		{
			front = rear = NULL;
		}
		else
		{
			front = front->next;
		}
		delete location;
	}
}
//Length function
//Post Condition: Returns the current size of queue
int Queue::length()
{
	NodeType *tempPtr = front;
	int countNodes = 0;
	while (tempPtr != NULL)
	{
		countNodes++;
		tempPtr = tempPtr-> next;
	}
	return countNodes;
}
//Print function
//Post Condition: Prints the queue
void Queue::Print()
{
	if (IsEmpty())
	{
		cout << "Queue is Empty!" << endl;
	}
	else
	{
		NodeType *tempPtr = front;
		while (tempPtr != NULL)
		{
			cout << tempPtr->info << " ";
			tempPtr = tempPtr->next;
		}
	}
	cout << endl;
}
//Deconstructer
//Post Condition: Deallocates the queue..
Queue::~Queue()
{
	MakeEmpty();
	delete front;
	delete rear;
}

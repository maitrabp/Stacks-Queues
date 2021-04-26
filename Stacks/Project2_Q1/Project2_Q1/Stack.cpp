/*Author: Maitra Patel
* Date Created: 3/10/2018
* Date Modified: 3/18/2018
* Purpose: Create a Stack of type int using linked list, and also have a copy constructer to copy one stack to another.
*/

#include <iostream>
#include "Stack.h"

using namespace std;

//Constructor
Stack::Stack()
{
	head = NULL;
	top = 0;
}
//Copy constructor
//Pre-Condition: A stack to copy from
//Post-Condition: Returns the copied stack.
Stack::Stack(Stack &x)
{
	//Initializes current stack first..
	head = NULL;
	top = 0;
	//If the head of new stack is NULL, then make this stack NULL as well..
	if (x.head == NULL)
	{
		this->head = NULL;
	}
	//Else, copy each element of new stack to this stack.. 
	else
	{
		//Deep Copy
		NodeType *currPtr = x.head;
		while (currPtr != NULL)
		{
			AppendList(currPtr->info);
			top++;
			currPtr = currPtr->next;
		}
	}
}
//Append  (FUNCTION ONLY TO BE USED FOR COPY CONSTRUCTOR)
//Pre-Condition: A number of type int
//Post-Condition: Creates a new node with the value passed & links it with the end of list.
void Stack::AppendList(int data)
{
	//Use temp pointer to iterate
	NodeType *tempPtr;
	//If first node does not exist..
	if (head == NULL)
	{
		head = new NodeType;
		head->info = data;
		head->next = NULL;
	}
	//else, find last node and create a new node after it..
	else
	{
		//Find last node..
		tempPtr = head;
		while (tempPtr->next != NULL)
		{
			tempPtr = tempPtr->next;
		}
		//Create newNode..
		tempPtr->next = new NodeType;
		tempPtr->next->info = data;
		tempPtr->next->next = NULL;
	}
}
//MakeEmpty Function 
//Post-Condition: Clears the whole stack
void Stack::MakeEmpty()
{
	while (head != NULL)
	{
		Pop();
	}
} 
//IsEmpty Function 
//Post-Condition: Returns if stack is empty or not
bool Stack::IsEmpty()
{
	return (head == NULL);
}
//IsFull Function 
//Post-Condition: Returns if stack is full or not.
bool Stack::IsFull()
{
	return (length() == 100);
}
//Length of Stack Function
//Returns the number of elements in stack
int Stack::length()
{
	NodeType *tempPtr = head;
	int countElements = 0;
	while (tempPtr != NULL)
	{
		countElements++;
		tempPtr = tempPtr->next;
	}
	return countElements;
}
//Print Function
//Post-Condition: Prints the stack
void Stack::Print()
{
	if (IsEmpty())
	{
		cout << "Stack is empty!" << endl;
	}
	else
	{
		NodeType *tempPtr = head;
		while (tempPtr != NULL)
		{
			cout << tempPtr->info << endl;
			tempPtr = tempPtr->next;
		}
	}
}
//Push Function
//Pre-Condition: An integer or a data point to be inserted into stack
//Post-Condition: Adds an element to top of stack.
void Stack::Push(int x)
{
	if (IsFull())
	{
		cout << "Error: Cannot Push, stack is full" << endl;
	}
	else
	{
		NodeType *location = new NodeType;
		location->info = x;
		location->next = head;
		head = location;
		top = head->info;
	}
}
//Pop Function 
//Post-Condition: Removes top element from stack
void Stack::Pop()
{
	if (IsEmpty())
	{
		cout << "Error: Cannot Pop, stack is already empty" << endl;
	}
	else
	{
		//Delete Top Node
		NodeType *location = head;
		if (head->next != NULL)
		{
			head = head->next;
			top = head->info;
		}
		else
		{
			//Assign head to NULL
			head = NULL;
			top = NULL;
		}
		delete location;
	} 
}
//To print the top value
int Stack::getTop()
{
	return top;
}
//Destructor
//Post-Condition: Deallocates the stack
Stack::~Stack()
{
	if (head != NULL)
	{
		MakeEmpty();
	}
	delete head;
}
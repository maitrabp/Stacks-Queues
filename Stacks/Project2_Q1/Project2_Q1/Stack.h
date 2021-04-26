/*Author: Maitra Patel
* Date Created: 3/10/2018
* Date Modified: 3/18/2018
* Purpose: Create a Stack of type int using linked list, and also have a copy constructer to copy one stack to another.
*/


#ifndef STACK_H
#define STACK_H

struct NodeType
{
	int info;
	NodeType* next;
};
class Stack
{
private:
	int top;
	NodeType *head; // It points to the head of a singly-linked list
public:

	Stack(); // default constructor: Stack is created and empty

	Stack(Stack &x); // copy constructor

	void MakeEmpty(); // Stack is made empty

	bool IsEmpty(); // test if the stack is empty

	bool IsFull(); // test if the stack is full; assume MAXITEM=100

	int length(); // return the number of elements in the stack

	void Print(); // print the value of all elements in the stack in the sequence
				  // from the top to bottom

	void Push(int x); // insert x onto the stack

	void Pop(); // delete the top element from the stack
					  // Precondition: the stack is not empty

	void AppendList(int data); //Function used solely for copy constructor..

	int getTop(); //In order to print the top value..


	~Stack(); // Destructor
};

#endif !STACK_H

/*Author: Maitra Patel
* Date Created: 3/10/2018
* Date Modified: 3/18/2018
* Purpose: Create a Queue of type string using linked list, and also have a copy constructer to copy one queue to another.
*/
#ifndef QUEUE
#define QUEUE

struct NodeType {
	string info;
	NodeType *next;
};
class Queue
{
	private:
		NodeType *front; // It points to the front of a singly-linked list
		NodeType *rear; // It points to the end of a singly-linked list
	public:
		Queue(); // default constructor: Queue is created and empty
		Queue(const Queue &x); // copy constructor: implicitly called
							   // for a deep copy
		void MakeEmpty(); // Queue is made empty; you should deallocate all
						  // the nodes of the linked list
		bool IsEmpty(); // test if the queue is empty
		bool IsFull(); // test if the queue is full; assume MAXITEM=100
		int length(); // return the number of elements in the queue
		void Print(); // print the value of all elements in the queue in the sequence
					  // from the front to rear
		void Enqueue(string x); // insert x to the rear of the queue
								// Precondition: the queue is not full
		void Dequeue(); // delete the element from the front of the queue
								 // Precondition: the queue is not empty
		~Queue(); // Destructor: memory for the dynamic array needs to be deallocated
};
#endif !QUEUE

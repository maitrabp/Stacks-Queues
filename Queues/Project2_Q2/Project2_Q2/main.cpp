/*Author: Maitra Patel
* Date Created: 3/10/2018
* Date Modified: 3/18/2018
* Purpose: Create a Queue of type string using linked list, and also have a copy constructer to copy one queue to another.
*/
#include <string>
#include <iostream>

using namespace std;
#include "Queue.h"


int main()
{
	Queue StringQueue;
	string y;
	StringQueue.MakeEmpty();
	StringQueue.Dequeue();
	StringQueue.Enqueue("John");
	cout << "string length 3 = " << StringQueue.length() << endl;
	StringQueue.Enqueue("Brown");
	cout << "string length 4 = " << StringQueue.length() << endl;
	StringQueue.Enqueue("Betty");
	StringQueue.Dequeue();
	cout << "The string queue contains : " << endl;
	StringQueue.Print();
	Queue StringQueue2 = StringQueue;
	cout << "The string queue 2 contains: " << endl;
	StringQueue2.Print();
	StringQueue.MakeEmpty();
	cout << "The string queue 3 contains: " << endl;
	StringQueue.Print();  //FIXED ERROR: (Before: StringQueue2.Print(), After: StringQueue.Print()). 
						//I'm assuming you meant to print StringQueue after making it empty.. 
	system("pause");
	return 0;
}
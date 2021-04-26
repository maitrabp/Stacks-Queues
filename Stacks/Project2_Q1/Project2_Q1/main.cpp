/*Author: Maitra Patel
* Date Created: 3/10/2018
* Date Modified: 3/18/2018
* Purpose: Create a Stack of type int using linked list, and also have a copy constructer to copy one stack to another.
*/

#include <iostream>
#include "Stack.h"

using namespace std;

int main()
{
	Stack IntStack;

	IntStack.Pop();
	IntStack.Push(11);
	IntStack.Push(22);
	
	cout << "int length 1 = " << IntStack.length() << endl;

	IntStack.Pop();
	IntStack.Push(33);


	cout << "int length 2 = " << IntStack.length() << endl;
	cout << "The int stack contains : " << endl;
	IntStack.Print();

	IntStack.Push(44);
	IntStack.Push(55);
	IntStack.Push(66);


	if (IntStack.IsFull() == false)
		cout << "The int stack is not full " << endl;
	else
		cout << "The int stack is full !" << endl;
	Stack IntStack2(IntStack);

	cout << "The int stack2 contains : " << endl;

	IntStack2.Print();

	IntStack2.MakeEmpty();

	cout << "The int stack3 contains : " << endl;

	IntStack2.Print();

	system("pause");
	return 0;
}
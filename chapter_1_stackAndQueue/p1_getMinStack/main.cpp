#include "getMinStack_1.h"
#include "getMinStack_2.h"
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	//GetMinStack_1<int> myStack;
	GetMinStack_2<int> myStack;

	vector<int> v = { 3,4,5,1,2,1 };
	for (auto item : v)
	{
		myStack.push(item);
	}
	// test
	cout << myStack.GetMin() << endl; // 1
	myStack.pop();

	cout << myStack.GetMin() << endl; // 1
	myStack.pop();

	cout << myStack.GetMin() << endl; // 1
	myStack.pop();

	cout << myStack.GetMin() << endl; // 3
	myStack.pop();

	cout << myStack.GetMin() << endl; // 3
	myStack.pop();

	cout << myStack.GetMin() << endl; // 3
	myStack.pop();

	return 0;
}


// StackLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node()
	{
		data = 0;
		next = NULL;
	};
};

class Stack
{
public:
	Node* top;
	Stack() {
		top = NULL;
	};
	bool isempty() {
		return(top == NULL);
	}
	void Push(int item)
	{
		Node* newNode = new Node();
		newNode->data = item;
		if (isempty())
			top = newNode;
		else {
			newNode->next = top;
			top = newNode;
		}
	}

	void Display() 
	{
		if (isempty())
			cout << "no any items in stack to display\n";
		else
		{	
			Node* temp = top;
			while (temp!=NULL)
			{
				cout << temp->data << "\t";
				temp = temp->next;
			}
		}
	}

	int pop() 
	{
		if (isempty())
			cout << "stack is empty so that no item to pop\n";
		else
		{
		int delValue;
		Node* delNode = top;
		top = top->next;
		delNode->data = delValue;
		delete delNode;
		return delValue;
		}
	}

	int peek() {
		return top->data;
	}


	bool isFound(int item)
	{
		if (isempty()) {
			cout << "stack is emty already;\n";
			return 0;
		}
		else
		{
			Node* temp = top;
			while (temp != NULL)
			{
				if (temp->data == item)
					return true;
				temp = temp->next;
			}
			return false;
		}
	}

	int Count() {
		int counter = 0;
		if (isempty()) {
			return counter;
		}
		Node* temp = top;
		while (temp!=NULL)
		{
			counter++;
			temp = temp->next;
		}
		return counter;
	}
};

int main()
{
	cout << "Hello World to our stack !\n";
	Stack s;
	int item;
	//cout << "\n";
	//cout << "enter an item to check is found\n";
	//cin >> item;
	cout << ((s.Count()) == 0 ? "no any item in stack" : "the count of items in the stack is : " + s.Count());
	for (int i = 0; i < 3; i++)
	{
		cout << "\n";
		cout << "enter an item to push in the stack\n";
		cin >> item;
		s.Push(item);
		cout << "\n";
		s.Display();
	}
	cout << "all items in the stacke here they are :\n";
	s.Display();

	cout << "\n";
	cout << "enter an item to check is found\n";
	cin >> item;
	cout << ((s.isFound(item)) ? "yes,its found\n" : "no found\n");

	cout <<"counts of stack is "<< s.Count();
   
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

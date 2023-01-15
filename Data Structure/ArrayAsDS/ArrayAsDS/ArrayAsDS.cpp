// ArrayAsDS.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Array {
private:
	int sizeOfArray;
	int length;
	int* theArray;
public:
	Array(int arraySize)
	{
		theArray = new int[arraySize];
		sizeOfArray = arraySize;
		length = 0;
	}
	void Fill() {
		int numberOfItems;
		cout << "Enter number item want to fill the array \n";
		cin >> numberOfItems;
		if (numberOfItems > sizeOfArray) {
			cout << "this number greater then array size";
			return;
		}
		int item;
		for (int i = 0; i < numberOfItems; i++)
		{
			cout << "Enter the item of index "<<i<<endl	;
			cin >> item;
			theArray[i] = item;
			length ++;
		}
	}

	void Display() {
		for (int  i = 0; i <length; i++)
		{
			cout << "\t" << theArray[i];
			
		}
	}

	int GetSize() {
		return sizeOfArray;

	}
	int GetLength() {
		return length;
	}
	int Search(int key) {
		int index = -1;
		for (int  i = 0; i < length; i++)
		{
			if (theArray[i] == key) {
				index = i;
				break;
			}
		}
		return index;
	}

	void Append(int newItem) {
		theArray[length] = newItem;
		length++;
	}

	void Insert(int newIndex, int newItem)
	{
		if (newIndex < sizeOfArray&&newIndex>=0) {
		for (int i = length; i > newIndex; i--)
		{
			theArray[i] = theArray[i - 1];
		}
		theArray[newIndex] = newItem;
		length++;
		}
		else {
			cout << "this index out of range" << endl;
		}
	}
};

int main()
{
	int arrSize;
    cout << "THis array AS DS \n";
	cout << "enter array size \n";
	cin >> arrSize;
	Array myArray(arrSize);
	myArray.Fill();
	myArray.Display();
	cout << endl;
	cout<< "nubmer items is " << myArray.GetLength() << endl;
	cout<< "size of array is" << myArray.GetSize() << endl;
	//int key;
	cout << "enter the value to search in the array\n";
	//cin >> key;
	int indexOfKey;
	//indexOfKey = myArray.Search(key);
	//if (indexOfKey == -1) {
	//	cout << "Not found\n";
	//}
	//else
	//{
	//	cout << "your key in the index " << indexOfKey << endl;
	//}
	int newIndex;
	int newItem;
	//cout << "enter new item to append into the arrat \n";
	//cin >> newItem;
	//myArray.Append(newItem);
	cout << "now , you should inset an item \n";
		cout << "firs enter index that you insert the item in \n";
		cin >> newIndex;
		cout << " then inser an item \n";
		cin >> newItem;
	myArray.Insert(newIndex, newItem);

	myArray.Display();
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

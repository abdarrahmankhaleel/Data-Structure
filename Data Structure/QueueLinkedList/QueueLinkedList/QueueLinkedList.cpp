

// QueueLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
};

class Queue {
public:
    Node* front;
    Node* rear;
    Queue()
    {
        front = rear = NULL;
    }
    bool isempty() {
        return (front == NULL);
    }
    void enQueue(int item) 
    {
        Node* nodenew = new Node();
        nodenew->data = item;
        if (isempty())
            front = rear = nodenew;
        else
        {
            rear->next = nodenew;
            rear = nodenew;
        }
    }

    bool isFound(int item) 
    {
        Node* temp = front;
        while (temp!=NULL)
        {
            if (temp->data == item)
                return true;
            temp = temp->next;
        }
    return false;
    }


    void Display() 
    {
        Node* temp = front;
        while (temp != NULL) 
        {
            cout << temp->data << "\t";
            temp = temp->next;
        }
        cout << "\n";
    }
    int deQueue() 
    {
            int delValue=0;
        if (isempty())
            cout << "the queue is empty ,so no iteme to dequeue;";
        else
        {
           //so in this case only one item in the queue and that is front and rear at the same time,,and also impossible that front equal to rear equl to null becuase tat case if the queue is empty 
            front->data = delValue;
            if (front == rear) {
                delete front;
                front = rear = NULL;
            }
            else 
            {
                Node* delTemp = front;
                front = front->next;
                delete delTemp;
            }
            return delValue;
        }
    }



};
int main()
{
    int item;
    cout << "Hello World to our queue!\n";
    Queue q;


    cout << "quueu after ququeeu...\n";
    q.Display();
    for (int  i = 0; i < 3; i++)
    {
        cout << "enter an item to enqueue\n";
        cin >> item;
        q.enQueue(item);
        cout << "\n";
        cout << "the current queue is : \n";
        q.Display();
    }

    //cout << "the current queue is : \n";
    //q.Display();


    cout << "dequeue is runnuin...\n";
    q.deQueue();

    cout << "quueu after ququeeu...\n";
    q.Display();

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

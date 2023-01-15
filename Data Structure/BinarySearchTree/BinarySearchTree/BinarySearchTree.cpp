// BinarySearchTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* right;
    Node* left;
    Node(int value)
    {
        data = value;
        right = left = NULL;
    }
};

class Bst {
public:
    Node* root;
    Bst()
    {
        root = NULL;
    }

    Node* Insert(Node* r,int item) {
        if (r == NULL) {
            Node* newNode = new Node(item);
            r = newNode;
        }
        else if (item > r->data) {
            r->right=Insert(r->right, item);
        }
        else
        {
            r->left=Insert(r->left, item);
        }
        return r;
    }

    void Insert(int item) {
        root = Insert(root, item);
    }

    void PreOrder(Node* r) //root left right
    {
        if (r == NULL)
            return;
        cout << r->data << "\t";
        PreOrder(r->left);
        PreOrder(r->right);
    }
    void InOrder(Node* r) // left ROOT right
    {
        if (r == NULL)
            return;
        InOrder(r->left);

        cout << r->data << "\t";

        InOrder(r->right);
    }

    void OutOrder(Node* r) // left  right root
    {
        if (r == NULL)
            return;
        OutOrder(r->left);
        OutOrder(r->right);
        cout << r->data << "\t";
    }

    Node* FindMax(Node* r) 
    {
        if (r == NULL)
            return NULL;
        if (r->right==NULL)
        {
            return r;
        }
        else
        {
           return FindMax(r->right);
        }
    }

    Node* FindMin(Node* r) {
        if (r == NULL)
            return NULL;
        if (r->left == NULL) 
            return r;
        else
            return FindMin(r->left);
    }

    Node* Delete(Node* r, int key) 
    {
        if (r == NULL)
            return NULL;
        else
        {
            if (r->data == key)
            {
                if (r->left ==NULL&& r->right == NULL) {
                    r = NULL;
                }
                else if (r->left != NULL && r->right == NULL) {
                    //r->data = r->left->data;
                    //delete r->left;
                    r->data = r->left->data;
                    delete r->left;
                    r->left = NULL;
                }
                else if (r->right != NULL && r->left == NULL)
                {
                    r->data = r->right->data;
                    delete r->right;
                    r->right = NULL;
                }
                else {
                   Node* max= FindMax(r->left);
                   r->data = max->data;
                   r->left = Delete(r->left, max->data);
                }
            }
            else {
                if (key > r->data) {
                    r->right=Delete(r->right,key);
                }
                else if (key < r->data) {
                    r->left = Delete(r->left, key);
                }
            }
            return r;
           
        }
    }
};
int main()
{
    cout << "Hello World to out bst!\n";
    Bst bst;
    bst.Insert(45);
    bst.Insert(15);
    bst.Insert(79);
    bst.Insert(90);
    bst.Insert(10);
    bst.Insert(55);
    bst.Insert(12);
    bst.Insert(20);
    bst.Insert(50);

    bst.PreOrder(bst.root);
    cout << "\n\n";

    int Max=bst.FindMax(bst.root)->data;

    cout << "the max is "<<Max << "\n";


    int Min=bst.FindMin(bst.root)->data;

    cout << "the max is "<<Min << "\n";
    //bst.PreOrder(bst.root);
    //cout << "\n\n";


    //cout << " \n Delete Items \n ";
    //Node* result = bst.Delete(bst.root, 12);
    //cout << "\n preorder After Delete 12 \n ";
    //bst.PreOrder(result);

    Node* result = bst.Delete(bst.root, 15);
    cout << "\n preorder After Delete 15 \n ";
    bst.PreOrder(result);
    //bst.PreOrder(bst.root);
    //cout << "\n\n";

    //bst.OutOrder(bst.root);
    //cout << "\n\n";
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

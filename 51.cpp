#include <iostream>
#include <climits>
using namespace std;

class node
{

public:
    int data;

    node *next;

    node(int d1)
    {
        this->data = d1;
    }
};

class stack
{

    public:
        node *h = NULL;
        int size = 0;
        stack()
        {
            h = NULL;
        }

        void push(int d)
        {
            node *newNode = new node(d);
            if (size == 0)
            {
                newNode->next = NULL;
                h = newNode;
                size++;
                return;
            }

            newNode->next = h;

            h = newNode;
            size++;
    }

    int pop()
    {
        if (size != 0)
        {
            node *t = h;
            h = h->next;
            delete t;
            size--;

            return t->data;
        }

        return INT_MIN;
    }

    int top()
    {
        if (size != 0)
        {

            return h->data;
        }

        return INT_MIN;
    }

    int Size()
    {
        return size;
    }

    bool IsEmpty()
    {
        return size == 0;
    }
};

void PrinLL(node *head)
{

    node *h = head;
    while (h != NULL)
    {
        cout << h->data << " ";
        // cout<<" I am here!"<<endl;

        h = h->next;
    }

    cout << endl;
}

int main()
{

    stack head;
    head.push(4);
    head.push(6);
    head.push(9);
    head.push(0);
    head.push(14);

    cout << "Before popping\n";

    PrinLL(head.h);
    cout << "Theh size of the stack is "<<head.size<<endl;

    head.pop();

    cout << "After popping\n";
    PrinLL(head.h);
    cout << "Theh size of the stack is "<<head.size<<endl;
    cout<<"The stack is empty or not "<<head.IsEmpty()<<endl;

    return 0;
}
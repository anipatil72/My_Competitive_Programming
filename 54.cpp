#include <iostream>
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

void PrinLL(node *head)
{

    node *h = head;
    while (h != NULL)
    {
        cout << h->data << " ";

        h = h->next;
    }

    cout << endl;
}

class que
{

public:
    node *h = NULL;
    node *t = NULL;
    int c = 0;
    int size = 0;

    bool IsEmpty()
    {
        return size == 0;
    }

    void enque(int d)
    {
        node *NewNode = new node(d);
        if (c == 0)
        {
            NewNode->next = NULL;
            t = NewNode;
            h = t;
            c = 1;
        }

        NewNode->next = NULL;
        t->next = NewNode;
        t = NewNode;
        size++;
    }

    int deque()
    {
        if (size != 0)
        {
            node *temp = h;
            int a = temp->data;
            h = h->next;
            delete temp;
            size--;
            return a;
        }

        return INT_MIN;
    }

    int front()
    {
        if (size != 0)
        {
            return h->data;
        }
        return INT_MIN;
    }

    int GetSize()
    {
        return size;
    }
};

int main()
{

    que q1;

    q1.enque(10);
    q1.enque(20);
    q1.enque(30);
    q1.enque(40);
    q1.enque(50);

    PrinLL(q1.h);

    cout << q1.deque() << endl;
    q1.enque(500);
    PrinLL(q1.h);

    return 0;
}
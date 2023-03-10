#include <iostream>
using namespace std;

class Node
{

public:
    int data;
    Node *next;

    Node(int a)
    {
        this->data = a;
        this->next = NULL;
    }
};

Node *DeleteR(Node *h)
{

    if (h == NULL)
    {
        return h;
    }
}

int LenR(Node *h)
{

    if (h->next == NULL)
    {
        return 1;
    }

    return 1 + LenR(h->next);
}

Node *DeleteatI(Node *h, int index)
{

    int i, j, k;
    Node *p;
    p = h;
    Node *t1;

    if (index == 1)
    {
        Node *t = h;
        // Node *NewNode = new Node(element);

        h = h->next;

        delete t;

        return h;
    }

    // Node *NewNode = new Node(element);

    for (i = 0; i < index - 2; i++)
    {

        // cout<<"\nI am here ! \n";
        p = p->next;
        // cout<<"\nThis is current data of p "<<p->data<<endl;
        if (p == NULL)
        {
            break;
        }
    }

    if (p != NULL)
    {

        // cout<<" I am here! \n";

        t1 = p->next;

        p->next = t1->next;
        delete t1;
    }
    else
    {
        cout << "\nDeletion not Possible\n";
    }

    return h;
}

Node *InsertAtI(Node *h, int index, int element)
{

    if (index == 1)
    {
        // Node *t = h;
        Node *NewNode = new Node(element);

        NewNode->next = h;
        h = NewNode;

        return h;
    }

    Node *t = h;
    Node *NewNode = new Node(element);

    for (int i = 0; i < index - 2; i++)
    {
        t = t->next;
        if (t == NULL)
        {
            break;
        }
    }

    if (t != NULL)
    {

        NewNode->next = t->next;
        t->next = NewNode;
    }
    else
    {
        cout << "\nDeletion not Possible\n";
    }

    return h;
}

void PrinI(Node *h, int index)
{

    Node *t = h;
    for (int i = 0; i < index; i++)
    {
        t = t->next;
    }

    cout << t->data << endl;
}

void PrinLL(Node *head)
{

    Node *h = head;
    while (h != NULL)
    {
        cout << h->data << " ";
        // cout<<" I am here!"<<endl;

        h = h->next;
    }
}

Node *LinListInput()
{

    Node *h = NULL;
    Node *tail;

    int a;

    cin >> a;
    while (a != -1)
    {
        Node *NewNode = new Node(a);

        if (h == NULL)
        {

            h = NewNode;
            tail = NewNode;
        }

        else
        {
            tail->next = NewNode;
            tail = tail->next;
        }

        cin >> a;
    }
    return h;
}

int main()
{

    int a, n;

    // cin >> n;

    Node *head;
    head = LinListInput();

    cout << LenR(head) << endl;

    // cout << "Before Deletion" << endl;
    // PrinLL(head);

    // head = DeleteatI(head, 3);

    // cout << "\nAfter Deletion" << endl;
    // PrinLL(head);
    return 0;
}
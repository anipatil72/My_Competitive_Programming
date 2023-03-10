#include <bits/stdc++.h>
using namespace std;

class ListNode
{

public:
    int val;
    ListNode *next;

    ListNode(int a)
    {
        this->val = a;
        this->next = NULL;
    }
};

ListNode *LinListInput()
{

    ListNode *h = NULL;
    ListNode *tail;

    int a;

    cin >> a;
    while (a != -1)
    {
        ListNode *NewListnode = new ListNode(a);

        if (h == NULL)
        {

            h = NewListnode;
            tail = NewListnode;
        }

        else
        {
            tail->next = NewListnode;
            tail = tail->next;
        }

        cin >> a;
    }
    return h;
}

ListNode *SortLL(ListNode *h)
{

    // if (h == NULL)
    // {
    //     return NULL;
    // }

    // h->next = SortLL(h->next);

    // if (h->val > h->next->val)
    // {
    //     ListNode *t = h->next;
    //     ListNode *temp = h->next;
    //     while (t->val < h->val && t->next != NULL)
    //     {
    //         t = t->next;
    //     }

    //     h->next = t->next;
    //     t->next = h;

    //     return temp;
    // }

    // return h;

    if (h == NULL)
    {
        return NULL;
    }

    ListNode *s = SortLL(h->next);

    if (s != NULL && h->val > s->val)
    {
        ListNode *t = s;
        ListNode *p = s;

        while (t->val < h->val)
        {
            p = t;
            t = t->next;

            if (t == NULL)
            {
                break;
            }
        }

        h->next = p->next;
        p->next = h;

        return s;
    }

    h->next = s;

    return h;
}

void PrinLL(ListNode *head)
{

    ListNode *h = head;
    while (h != NULL)
    {
        cout << h->val << " ";
        // cout<<" I am here!"<<endl;

        h = h->next;
    }
}

int main()
{

    ListNode *Head = LinListInput();

    Head = SortLL(Head);

    PrinLL(Head);

    return 0;
}
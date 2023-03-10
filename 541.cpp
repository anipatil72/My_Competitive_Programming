#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void deleteNode(ListNode *node)
{

    ListNode *p = node;

    ListNode *t = node->next;


    ListNode* h;

    while (t != NULL)
    {
        p->val = t->val;


        if (t->next==NULL)
        {
             h = t;   
        }
        

        p = p->next;
        t = t->next;
    }

    h->next = NULL;
}

int main()
{

    return 0;
}
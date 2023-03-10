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



ListNode *Merge(ListNode *h1, ListNode *h2)
{
    ListNode *fH;
    ListNode *fT;
    ListNode *t;

    int c = 0;

    fH = (h1->val < h2->val) ? (h1) : (h2);

    fT = fH;

    while (h1 != NULL && h2 != NULL)
    {

        if (fT == h1)
        {
            h1 = h1->next;

            if (h1 == NULL)
            {
                fT->next = h2;
                break;
            }

            t = (h1->val < h2->val) ? (h1) : (h2);
            fT->next = t;
            fT = t;
        }
        else if (fT == h2)
        {

            h2 = h2->next;

            if (h2 == NULL)
            {
                fT->next = h1;
                break;
            }

            t = (h1->val < h2->val) ? (h1) : (h2);
            fT->next = t;
            fT = t;
        }
    }

    return fH;
}




int main() 
{

return 0;
}
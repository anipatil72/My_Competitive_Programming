// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *oddEvenList(ListNode *head)
{

    int count = 0;

    if (head == NULL)
    {
        return head;
    }

    ListNode *evenstart = head;

    ListNode *oddstart = head->next;

    if (oddstart == NULL)
    {
        return head;
    }

    ListNode *even = head;
    ListNode *odd = head->next;

    ListNode *evenend = NULL;

    while (even != NULL && odd != NULL)
    {

        if (even->next != NULL)
        {
            even->next = even->next->next;

            if (even->next->next == NULL)
            {
                evenend = even;
            }

            even = even->next->next;
        }

        if (odd->next != NULL)
        {
            odd->next = odd->next->next;

            odd = odd->next->next;
        }
    }

    odd->next = NULL;

    if (evenend != NULL)
    {
        evenend->next = oddstart;
    }
    else
    {
        even->next = oddstart;
    }

    return evenstart;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
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

ListNode *deleteDuplicates(ListNode *h)
{

    if (h == NULL)
    {
        return h;
    }

    if (h->next == NULL)
    {
        return h;
    }

    bool check = false;

    while (h != NULL && h->next != NULL && h->val == h->next->val)
    {
        h = h->next;

        check = true;
    }

    if (h == NULL || h->next == NULL)
    {
        return NULL;
    }

    if (check)
    {
        h = h->next;
    }

    ListNode *prev = NULL;

    // int count = 0;

    bool flag = true;

    ListNode *cur = h;

    while (cur != NULL && prev != NULL)
    {
        if ((cur != NULL && cur->next != NULL) && cur->val == cur->next->val)
        {

            int d = cur->val;

            while (cur != NULL && cur->val == d)
            {
                cur = cur->next;
            }

            cur = cur->next;
        }
        else
        {
            if (flag)
            {
                prev = cur;
                flag = false;
            }
            else
            {

                prev->next = cur;

                prev = cur;
            }

            cur = cur->next;
        }

        if (cur == NULL || cur->next == NULL)
        {

            if (cur == NULL)
            {

                if (flag)
                {
                    return NULL;
                }
                else
                {
                    prev->next = NULL;

                    return h;
                }
            }

            prev = cur;

            // prev = prev->next;

            prev->next = NULL;

            return h;
        }
    }

    return h;
}

int main()
{

    return 0;
}
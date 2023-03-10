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

ListNode *Mid(ListNode *h)
{
    ListNode *slow = h;
    ListNode *fast = h;

    fast = h->next;

    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;

        fast = fast->next->next;
    }

    if (fast->next != NULL && fast->next->next == NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

ListNode *RevLLI(ListNode *h)
{

    ListNode *t = h;
    ListNode *h1;
    ListNode *h2;
    ListNode *h3;

    h1 = h->next;
    // cout<<h1->val<<endl;

    while (h1 != NULL)
    {

        h2 = t;

        t = h1;

        h1 = t->next;

        t->next = h2;
        // cout<<t->val<<endl;
        // t= h3 ;
    }

    t->next = h2;

    h->next = NULL;

    return t;
}

bool isPalindrome(ListNode *head)
{

    vector<int> v;

    ListNode *t = head;

    while (t != NULL)
    {
        v.push_back(t->val);
        t = t->next;
    }

    bool flag = true;

    int n = v.size();

    for (int i = 0; i < n / 2; i++)
    {
        if (v[i] != v[n - 1 - i])
        {
            flag = false;
            break;
        }
    }

    return flag;
}

int main()
{

    return 0;
}
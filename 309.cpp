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

ListNode *reverseBetween(ListNode *head, int left, int right)
{

    stack<int> s;

    ListNode *t = head;

    int count = 0;

    while (count < left - 1)
    {
        t = t->next;
        count++;
    }

    while (count <= right - 1)
    {
        s.push(t->val);
        t = t->next;
        count++;
    }

    t = head;

    count = 0;

    while (count < left -1)
    {
        t = t->next;
        count++;
    }

    while (count <= right-1)
    {
        int d = s.top();

        s.pop();

        t->val = d;

        t = t->next;

        count++;
    }

    return head;
}

int main()
{

    return 0;
}
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

ListNode *removeNthFromEnd(ListNode *head, int n)
{

    int count = 0;

    ListNode* t = head;

    while (t!=NULL)
    {
        count++;
        t = t->next;
    }

    if (count==1)
    {
       return NULL;     
    }

    
    
    

    int target = count - n - 1;

    if (target==count)
    {
         head = head->next;
         return head;   
    }
    

    int cnt = 0;

    t = head;

    while (cnt<target)
    {
        cnt++;

        t = t->next;

    }

    ListNode* f = t->next->next;

    ListNode* d = t->next;

    t->next = f;

    delete d;

    
}

int main()
{

    return 0;
}
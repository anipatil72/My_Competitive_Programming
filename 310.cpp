#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

int solve(ListNode *A, int B)
{


    int n = 0 ;

    ListNode* t  = A ;

    while (t!=NULL)
    {
       n++;
       t = t->next;
    }

    int mid = n/2;

    if (mid-B<0)
    {
            return -1;
    }

    int count = 0 ;

    t = A;

    while (count<(mid-B))
    {
        count++;
        t = t->next;
        
    }


    return t->val;
    
    
    
}

int main()
{

    return 0;
}
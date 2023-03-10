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

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{

    ListNode *u = l1;
    ListNode *d = l2;

    int t;

    int carry = 0;

    string s = "";

    while (d != NULL && u != NULL)
    {
        int cur = d->val + u->val + carry;
        carry = cur / 10;

        s += to_string(cur%10);

        d = d->next;
        u = u->next;
    }

    while (d != NULL)
    {
        int cur = d->val + carry;
        carry = cur / 10;

        s += to_string(cur%10);
        d = d->next;
    }

    while (u != NULL)
    {
        int cur = u->val + carry;
        carry = cur / 10;

        

        s += to_string(cur%10);
        u = u->next;
    }

    if (carry != 0)
    {
        s += to_string(carry);
    }

    // reverse(s.begin(), s.end());

    int n = s.length();


   
    



    
    

   

    while (s.back()=='0'&&s.length()>1)
    {

        s.pop_back();
      
    }

    ListNode *h = new ListNode(stoi(s.substr(0, 1))) ;

    ListNode *prev = h;

    for (int i =  1; i < n; i++)
    {

        ListNode *newNode = new ListNode(stoi(s.substr(i, 1)));


        cout<<s.substr(i, 1)<<" ";

        prev->next = newNode;
        // newNode->next = NULL;

        prev = newNode;
    }

    prev->next = NULL;



    return h ;
}

int main()
{

    return 0;
}
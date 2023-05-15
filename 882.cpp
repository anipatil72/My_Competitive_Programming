// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *swapNodes(ListNode *head, int k)
{
    int n = 0;

    ListNode *tem = head;

    while (tem != NULL)
    {
        n++;

        tem = tem->next;
    }

    int last = n + 1 - k;

    int cur = 1;

    tem = head;

    ListNode *fir, *sec;

    while (tem != NULL)
    {
        if (cur == k)
        {
            fir = tem;
        }

        if (cur == last)
        {
            sec = tem;
        }

        cur++;

        tem = tem->next;
    }

    swap(fir->val, sec->val);

    return head;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
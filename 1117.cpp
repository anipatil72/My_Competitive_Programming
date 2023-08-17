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

ListNode *partition(ListNode *head, int x)
{
    ListNode *fir = head;

    ListNode *sec = head;

    while (sec != NULL)
    {
        if (sec->val < x)
        {
            swap(fir->val, sec->val);

            fir = fir->next;

            sec = sec->next;
        }
        else
        {
            // fir = fir->next;

            sec = sec->next;
        }
    }

    return head;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
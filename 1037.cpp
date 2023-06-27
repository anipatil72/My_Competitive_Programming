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

ListNode *mergeNodes(ListNode *head)
{
    int temp = 0;

    ListNode *des = head->next;

    ListNode *prev = head;

    ListNode *kam = NULL;

    ListNode *ans = NULL;

    while (des != NULL)
    {
        temp += des->val;

        if (des->val == 0)
        {
            des->val = temp;

            temp = 0;

            if (ans == NULL)
            {
                ans = des;
            }

            if (kam == NULL)
            {
                kam = des;
            }
            else
            {
                kam->next = des;

                kam = des;
            }
        }

        des = des->next;
    }

    kam->next = NULL;

    return ans;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
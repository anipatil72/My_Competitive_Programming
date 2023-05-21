// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;
using namespace __gnu_pbds;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

ListNode *detectCycle(ListNode *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    if (head->next == head)
    {
        return head;
    }

    ListNode *slow = head;

    ListNode *fast = head;

    bool flag = true;

    while (slow != fast)
    {
        ListNode *tem = fast->next;

        if (tem == NULL)
        {
            return NULL;
        }

        fast = tem->next;

        if (fast == NULL)
        {
            return NULL;
        }

        slow = slow->next;

        if (slow == fast)
        {
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
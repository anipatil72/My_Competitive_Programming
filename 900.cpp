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

ListNode *reverseList(ListNode *head)
{
    if (head == NULL)
    {
        return head;
    }

    ListNode *tem = head;

    ListNode *cur = NULL;

    while (tem != NULL)
    {

        ListNode *here = tem->next;

        tem->next = cur;

        cur = tem;
        tem = here;
    }

    return cur;
}

ListNode *removeNodes(ListNode *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    ListNode *rev = reverseList(head);

    ListNode *fav = rev;

    int cur = rev->val;

    ListNode *tem = rev->next;

    while (tem != NULL)
    {
        if (cur <= tem->val)
        {
            fav->next = tem;

            // ListNode *here = tem->next;

            cur = tem->val;

            fav = tem;
        }

        tem = tem->next;
    }

    fav->next = NULL;

    return reverseList(rev);
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
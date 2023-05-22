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

vector<int> nextLargerNodes(ListNode *head)
{
    if (head == NULL)
    {
        return {};
    }

    if (head->next == NULL)
    {
        return {0};
    }

    ListNode *rev = reverseList(head);

    stack<int> s;

    ListNode *tem = rev;

    vector<int> ans;

    while (tem != NULL)
    {
        if (s.empty())
        {
            s.push(tem->val);

            ans.push_back(0);
        }
        else
        {
            int t = s.top();

            while ((!s.empty()) && (tem->val >= s.top()))
            {
                s.pop();
            }

            if (s.empty())
            {
                ans.push_back(0);
                s.push(tem->val);
            }
            else
            {
                ans.push_back(s.top());
            }
            s.push(tem->val);
        }

        tem = tem->next;
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
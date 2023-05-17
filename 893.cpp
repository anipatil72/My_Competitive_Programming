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
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

int pairSum(ListNode *head)
{
    vector<int> v;

    ListNode *tem = head;

    while (tem != NULL)
    {
        v.push_back(tem->val);
    }

    int maxi = INT_MIN;

    int n = v.size();

    for (int i = 0; i < n / 2; i++)
    {
        maxi = max(maxi, v[i] + v[n - 1 - i]);
    }

    return maxi;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
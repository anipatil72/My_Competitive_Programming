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

void deleteMid(stack<int> &s, int sizeOfStack)
{
    int n = sizeOfStack, req = n / 2;

    stack<int> des;

    int count = 0;

    while (!s.empty())
    {
        int dec = s.top();

        s.pop();

        if (count < req)
        {
            des.push(dec);
        }

        count++;
    }

    while (!des.empty())
    {
        s.push(des.top());

        des.pop();
    }
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
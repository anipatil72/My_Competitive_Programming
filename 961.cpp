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

int nthUglyNumber(int n)
{
    priority_queue<int, vector<int>, greater<int>> q;

    int count = 0, tem = 0;

    q.push(1);

    while (count < n)
    {
        int fof = q.top();

        q.pop();

        while (!q.empty() && q.top() == fof)
        {
            q.pop();
        }

        tem = fof;

        // cout << tem << endl;

        q.push(2 * fof);
        q.push(3 * fof);
        q.push(5 * fof);

        count++;
    }

    return tem;
}

int main()
{

    int n = 10;

    cout << nthUglyNumber(n);

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
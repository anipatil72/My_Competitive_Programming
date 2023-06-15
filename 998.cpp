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

long long maxDiamonds(int A[], int N, int K)
{
    priority_queue<int> q;

    for (int i = 0; i < N; i++)
    {
        q.push(A[i]);
    }

    int k = K;

    long long ans = 0;

    while (k-- && !q.empty())
    {
        ans += q.top();

        int tt = q.top();

        if (tt == 0)
        {
            break;
        }

        q.pop();

        q.push(tt / 2);
    }

    return ans;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
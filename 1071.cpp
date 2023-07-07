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

double recur(double x, long long n)
{
    if (n == 1)
    {
        return x;
    }

    if (n & 1)
    {
        return (x * recur(x, n - 1));
    }

    double y = recur(x, n / 2);

    return y * y;
}

double myPow(double x, int n)
{

    if (x == 0)
    {
        return 0;
    }

    if (n == 0)
    {
        return 1.0;
    }
    else if (n < 0)
    {
        double ans = recur(x, -1 * 1LL * n);

        return 1.0 / ans;
    }

    return recur(x, n);
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
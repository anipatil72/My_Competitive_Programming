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

int maximumProfit(vector<int> &prices)
{
    int n = prices.size();

    int fir = prices[0];

    int profit = 0;

    for (int i = 1; i < n; i++)
    {
        int cost = prices[i] - fir;

        profit = max(profit, cost);

        fir = min(fir, prices[i]);
    }

    return profit;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
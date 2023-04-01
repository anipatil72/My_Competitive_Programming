// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;

int mincostTickets(vector<int> &days, vector<int> &costs)
{
    int n = days.size();

    ll ans = 0;

    long double cost1 = 1.0L * costs[0], cost2 = 1.0L * costs[1] / 7, cost3 = 1.0L * costs[2] / 30;

    int i = 0;

    while (i < n)
    {
        int cur = days[i];

        int week = 0, weeklast = 0;

        int pos = i;

        if (pos == n - 1)
        {
            ans += (costs[0]);

            i++;

            continue;
        }

        while (pos + 1 < n && (days[pos + 1] - cur + 1) <= 7)
        {
            week++;

            weeklast = pos + 1;
            pos++;
        }

        int month = 0, monthlast = 0;

        pos = i;

        while (pos + 1 < n && (days[pos + 1] - cur + 1) <= 30)
        {
            month++;

            monthlast = pos + 1;

            pos++;
        }

        if (cost1 * week < cost2)
        {
        }
    }
}

int main()
{

    return 0;
}

//
// days = [1,4,6,7,8,20], costs = [2,7,15]
// Output: 11

// ॥ जय श्री राम जय श्री कृष्ण ॥
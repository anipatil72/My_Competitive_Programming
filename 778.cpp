// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define M 1000000007
using namespace std;

int maxProfit(vector<int> &prices)
{
    int mini = prices[0];

    int n = prices.size();

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        ans = max(ans, abs(prices[i] - mini));

        mini = min(prices[i], mini);
    }

    return ans;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
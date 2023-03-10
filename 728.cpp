// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define M 1000000007
using namespace std;

ull nthCatalanNumber(ull n)
{
    vector<ull> dp(n + 1, 0);

    dp[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            dp[i] += dp[j] * dp[i - j - 1];
        }
    }

    return dp[n];
}

int main()
{

    cout << nthCatalanNumber(10);

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
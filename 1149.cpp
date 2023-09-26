#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> h(n), nxtBetter(n, n), nxtWorse(n, n), dp(n, INT_MAX);

    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }

    // Using monotonic stack to find next better and worse SUV
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && h[s.top()] <= h[i])
        {
            nxtBetter[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }

    while (!s.empty())
        s.pop();

    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && h[s.top()] >= h[i])
        {
            nxtWorse[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }

    // DP to find min jumps
    dp[0] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        dp[i + 1] = min(dp[i + 1], dp[i] + 1);

        int better = nxtBetter[i];
        if (better < n && *max_element(h.begin() + i + 1, h.begin() + better) < h[i])
        {
            dp[better] = min(dp[better], dp[i] + 1);
        }

        int worse = nxtWorse[i];
        if (worse<n && * min_element(h.begin() + i + 1, h.begin() + worse)> h[i])
        {
            dp[worse] = min(dp[worse], dp[i] + 1);
        }
    }

    cout << dp[n - 1] << "\n";
    return 0;
}

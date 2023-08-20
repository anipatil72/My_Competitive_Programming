// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

int maxPoints(int N, vector<int> &colors)
{
    vector<int> dp(N, 0);

    for (int i = 0; i < N; ++i)
    {
        unordered_map<int, int> color_count;
        int max_points = 0;

        for (int j = i; j >= 0; --j)
        {
            color_count[colors[j]]++;

            int points = (i - j + 1) * (i - j + 1);

            int max_color_count = 0;
            for (const auto &pair : color_count)
            {
                max_color_count = max(max_color_count, pair.second);
            }

            points += max_color_count * max_color_count;

            if (j > 0)
            {
                max_points = max(max_points, dp[j - 1] + points);
            }
            else
            {
                max_points = max(max_points, points);
            }
        }

        dp[i] = max_points;
    }

    return dp[N - 1];
}

int main()
{
    int N = 6;
    vector<int> colors = {1, 1, 2, 2, 1, 3};
    cout << maxPoints(N, colors) << endl; // Output: 41

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
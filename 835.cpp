// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;

int maxIntersections(vector<vector<int>> lines, int N)
{
    map<int, int> m;

    for (int i = 0; i < N; i++)
    {
        m[lines[i][0]]++;
        m[lines[i][1] + 1]--;
    }

    ll ans = 0;

    ll sum = 0;

    for (auto x : m)
    {
        sum += (x.second);

        ans = max(ans, sum);
    }

    return ans;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
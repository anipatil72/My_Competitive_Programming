// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#define ll long long
#define M 1000000007
using namespace std;

vector<ll> answerQueries(vector<int> &nums, vector<int> &queries)
{

    ll n = nums.size();

    ll m = queries.size();

    sort(nums.begin(), nums.end());

    vector<ll> pre(n);

    pre[0] = nums[0];

    for (ll i = 1; i < n; i++)
    {

        pre[i] = pre[i - 1] + nums[i];
    }

    vector<ll> ans(m);

    for (ll i = 0; i < m; i++)
    {
        auto it = upper_bound(pre.begin(), pre.end(), queries[i]);

        ll d = abs(distance(pre.begin(), it));

        ans[i] = d;
    }

    return ans;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
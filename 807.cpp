// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;

vector<long long> minOperations(vector<int> &nums, vector<int> &queries)
{

    int num = nums.size();

    int n = queries.size();

    vector<long long> ans(n);

    ll sum = 0;

    for (int i = 0; i < num; i++)
    {
        sum += nums[i];
    }

    for (int i = 0; i < n; i++)
    {

        ans[i] = abs(num * 1LL * queries[i] - sum);
    }

    return ans;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
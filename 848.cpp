// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;
using namespace __gnu_pbds;

vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
{
    int n = candies.size();

    int maxi = *max_element(candies.begin(), candies.end());

    vector<bool> ans(n, 0);

    for (int i = 0; i < n; i++)
    {
        if (extraCandies + 0LL + candies[i] >= maxi)
        {
            ans[i] = true;
        }
    }

    return ans;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
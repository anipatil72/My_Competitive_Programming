// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#define ll long long
#define M 1000000007
using namespace std;

int maxIceCream(vector<int> &costs, int coins)
{
    int n = costs.size();

    sort(costs.begin(), costs.end());

    vector<long long> pref(n);

    pref[0] = costs[0];

    for (int i = 1; i < n; i++)
    {

        pref[i] = pref[i - 1] + costs[i];
    }

    auto it = upper_bound(pref.begin(), pref.end(), coins);

    int d = abs(distance(pref.begin(), it));

    return d;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;

// Principle of Inclusion and Exclusion

ll Number_of_Numbers(vector<int> &primes, ll Upperlimit)
{
    int n = primes.size();

    ll subsets = (1 << n) - 1;

    ll ans = 0;

    for (int i = 1; i <= subsets; i++)
    {
        int setbits = (__builtin_popcount(i));

        ll denom = 1;

        for (int j = 0; j < n; j++)
        {
            if ((i & (1 << j)))
            {
                denom *= (primes[j]);
            }
        }

        if (setbits % 2)
        {
            ans += (Upperlimit / denom);
        }
        else
        {
            ans -= (Upperlimit / denom);
        }
    }

    return ans;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
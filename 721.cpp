// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#define ll long long
#define M 1000000007
using namespace std;

ll Sqroot(ll x)
{
    ll low = 0, high = x, ans = -1;

    while (low <= high)
    {
        ll mid = low + (high - low) / 2;

        ll mSq = mid * mid;

        if (mSq == x)
        {
            return mid;
        }
        else if (mSq > x)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;

            ans = mid;
        }
    }

    return ans;
}

int main()
{

    // int n = 0;

    // int t = (1 << 30);

    // t = INT_MAX;

    // cout << t << endl;

    cout << Sqroot(100) << endl;

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
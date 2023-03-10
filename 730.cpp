// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define M 1000000007
using namespace std;

ll getPeak(vector<int> &a)
{

    ll n = a.size();

    ll low = 0, high = n - 1;

    ll mid = low + (high - low) / 2;

    while (low <= high)
    {
        mid = low + (high - low) / 2;

        if ((mid == 0 || a[mid] >= a[mid - 1]) && (mid == n - 1 || a[mid] <= a[mid + 1]))
        {
            return mid;
        }
        else
        {
            if (mid > 0 && a[mid] <= a[mid - 1])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
    }

    return -1;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define M 1000000007
using namespace std;

// Search in a rotated sorted array

ll BSearchRotated(vector<int> &a, ll key)
{
    int n = a.size();

    ll low = 0, high = n - 1;

    ll mid = low + (high - low) / 2;

    while (low <= high)
    {
        mid = low + (high - low) / 2;

        if (a[mid] == key)
        {
            return mid;
        }
        else
        {
            if (a[low] < a[mid])
            {
                // left half sorted

                if (key >= a[low] && key <= a[mid])
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            else
            {

                // right half sorted

                if (key >= a[mid] && key <= a[high])
                {
                    low = mid + 1;
                }
                else
                {

                    high = mid - 1;
                }
            }
        }
    }

    return -1;
}

int main()
{

    vector<int> v = {80, 90, 100, 10, 20, 30, 40, 50, 60, 70};

    ll key = 70;

    ll ans = BSearchRotated(v, key);

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#define ll long long
#define M 1000000007
using namespace std;

// function to find lower bound

int lowBound(vector<int> &a, int x)
{
    int n = a.size();

    if (n == 1)
    {
        if (x >= a[0])
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    int low = 0;

    int high = n - 1;

    int ans = 0;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        ans = mid;

        if (x < a[mid])
        {
            high = mid - 1;
        }
        else if (x > a[mid])
        {
            low = mid + 1;
        }
        else
        {
            if (mid == n - 1 || a[mid + 1] != a[mid])
            {
                return mid + 1;
            }
            else
            {
                low = mid + 1;
            }
        }
    }

    return ans + 1;
}

int main()
{

    vector<int> a = {1, 2, 2, 3, 4, 4, 4, 5, 7, 8, 8, 9};

    cout << lowBound(a, 0);

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
#include <bits/stdc++.h>
using namespace std;

bool isBadVersion(int x)
{
}

int firstBadVersion(int n)
{

    if (n == 1)
    {
        return 1;
    }

    int low = 0, high = n - 1;

    int mid = low + (high - low) / 2;
    // int mid = (low + 0LL + high)/2 ;

    while (high > low)
    {
        if (isBadVersion(mid))
        {
            high = mid;
        }
        else
        {
            low = mid ;
        }

        mid = low + (high - low) / 2;
    }

    return mid + 1;
}

int main()
{

    return 0;
}
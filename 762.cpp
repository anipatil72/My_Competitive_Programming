// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define M 1000000007
using namespace std;

int countOdds(int low, int high)
{
    int n = high - low + 1;

    int ans;

    if (n % 2 == 0)
    {

        ans = n / 2;
    }
    else if (low % 2 == 1)
    {
        ans = n / 2 + 1;
    }
    else
    {
        ans = n / 2;
    }

    return ans;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
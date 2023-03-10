// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#define ll long long
#define M 1000000007
using namespace std;

int climbStairs(int A)
{

    if (A<=1)
    {
            return 1;
    }


    return climbStairs(A-1) + climbStairs(A-2);
    
}

int main()
{

    cout << climbStairs(1);

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
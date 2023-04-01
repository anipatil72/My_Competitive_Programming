// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;

// Fast Exponentiation ( in Logarithmic Time )
ll fastExponentiation(ll base, ll exponent)
{

    if (exponent == 0)
    {
        return 1;
    }
    ll subproblem = fastExponentiation(base, exponent / 2);

    if (exponent & 1)
    {
        return base * subproblem * subproblem;
    }

    return subproblem * subproblem;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
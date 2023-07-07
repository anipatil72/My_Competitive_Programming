// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

// function to check prime
bool isPrime(int n)
{
    if (n == 1)
    {
        return false;
    }
    if (n == 2 || n == 3)
    {
        return true;
    }
    if (n % 2 == 0 || n % 3 == 0)
    {
        return false;
    }
    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0)
        {
            return false;
        }
        if (n % (i + 2) == 0)
        {
            return false;
        }
    }
    return true;
}

bool canReorderDoubled(vector<int> &arr)
{
    int n = arr.size();

    multiset<int> m;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
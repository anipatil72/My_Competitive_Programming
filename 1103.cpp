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

bool canIWin(int maxChoosableInteger, int desiredTotal)
{
    if (maxChoosableInteger <= desiredTotal)
    {
        return true;
    }

    vector<int> dp(desiredTotal + 1, 0);

    for (int i = 0; i <= maxChoosableInteger; i++)
    {
        dp[i] = 1;
    }

    int last = maxChoosableInteger + 1;

    dp[maxChoosableInteger + 1] = 0;

    for (int i = maxChoosableInteger + 2; i <= desiredTotal; i++)
    {
        
    }
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
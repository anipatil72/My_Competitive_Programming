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

long long recur(int index, vector<vector<int>> &a, vector<ll> &dp)
{
    long long n = a.size();

    if (index >= n)
    {
        return 0;
    }

    if (index == n - 1)
    {
        return a[n - 1][0];
    }

    if (dp[index] != -1)
    {
        return dp[index];
    }

    long long take = a[index][0] + recur(index + a[index][1] + 1, a, dp);

    long long nottake = recur(index + 1, a, dp);

    return dp[index] = max(take, nottake);
}

long long mostPoints(vector<vector<int>> &questions)
{
    int n = questions.size();

    vector<long long> dp(n + 1, -1);

    return recur(0, questions, dp);
}

int main()
{

    vector<vector<int>> v = {{1, 1},
                             {2, 2},
                             {3, 3},
                             {4, 4},
                             {5, 5}};

    cout << mostPoints(v);

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
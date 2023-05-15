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

int diagonalSum(vector<vector<int>> &mat)
{
    int n = mat.size();

    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += mat[i][i];
    }

    for (int i = 0; i < n; i++)
    {
        sum += mat[i][n - 1 - i];
    }

    if (n & 1)
    {
        sum -= mat[n / 2][n / 2];
    }

    return sum;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
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

bool checkStraightLine(vector<vector<int>> &coordinates)
{
    int n = coordinates.size();

    int mnum, mden, c;

    mnum = coordinates[0][1] - coordinates[1][1];

    mden = coordinates[0][0] - coordinates[1][0];

    int com = __gcd(abs(mnum), abs(mden));

    mnum /= com;

    mden /= com;

    c = coordinates[0][1] * 1LL * mden - coordinates[0][0] * 1LL * mnum;

    for (int i = 2; i < n; i++)
    {
        if (c != (coordinates[i][1] * 1LL * mden - coordinates[i][0] * 1LL * mnum))
        {
            return false;
        }
    }

    return true;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
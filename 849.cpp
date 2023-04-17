// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;
using namespace __gnu_pbds;

bool checkXMatrix(vector<vector<int>> &grid)
{
    int n = grid.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((i == j) || (i == n - 1 - j))
            {
                if (grid[i][j] == 0)
                {
                    return false;
                }
            }
            else
            {
                if (grid[i][j] != 0)
                {
                    return false;
                }
            }
        }
    }

    return true;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
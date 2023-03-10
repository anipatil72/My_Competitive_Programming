#include <bits/stdc++.h>
using namespace std;

int GCD(int a, int b)
{
    if (b == 0)
    {
        return a;
    }

    return GCD(b, a % b);
}

long long GiveNcR(int n, int r)
{

    // p holds the value of n*(n-1)*(n-2)...,
    // k holds the value of r*(r-1)...
    long long p = 1, k = 1;

    // C(n, r) == C(n, n-r),
    // choosing the smaller value
    if (n - r < r)
        r = n - r;

    if (r != 0)
    {
        while (r)
        {
            p *= n;
            k *= r;

            // gcd of p, k
            long long m = GCD(p, k);

            // dividing by gcd, to simplify
            // product division by their gcd
            // saves from the overflow
            p /= m;
            k /= m;

            n--;
            r--;
        }

        // k should be simplified to 1
        // as C(n, r) is a natural number
        // (denominator should be 1 ) .
    }

    else
        p = 1;

    // if our approach is correct p = ans and k =1
    // cout << p << endl;

    return p;
}

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{

    int n = obstacleGrid.size();

    int m = obstacleGrid[0].size();

    int x, y;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (obstacleGrid[i][j] == 1)
            {
                x = i;
                y = j;

                break;
            }
        }
    }

    long long ans = GiveNcR(n + m - 2, m - 1) - GiveNcR(x + y - 2, x - 1);

    return ans;
}

int main()
{

    // cout<<GCD(10,15);

    return 0;
}
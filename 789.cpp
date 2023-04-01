// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

int findCity(int n, int m, vector<vector<int>> &edges, int distanceThreshold)
{
    vector<vector<int>> mat(n, vector<int>(n, (int)1e9));

    for (int i = 0; i < n; i++)
    {
        mat[i][i] = 0;
    }

    for (int i = 0; i < m; i++)
    {
        mat[edges[i][0]][edges[i][1]] = edges[i][2];
        mat[edges[i][1]][edges[i][0]] = edges[i][2];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                mat[j][k] = min(mat[j][k], mat[j][i] + mat[i][k]);
            }
        }
    }

    int can = INT_MAX;

    int canbe = 0;

    for (int i = 0; i < n; i++)
    {
        int count = 0;

        for (int j = 0; j < n; j++)
        {

            if (mat[i][j] <= distanceThreshold)
            {
                count++;
            }
        }

        if (count <= can)
        {
            can= count;
            canbe = i;
        }
    }

    return canbe;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
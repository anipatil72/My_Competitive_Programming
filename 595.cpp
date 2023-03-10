#include <bits/stdc++.h>
using namespace std;

void gameOfLife(vector<vector<int>> &a)
{

    int m, n;

    m = a.size();

    n = a[0].size();

    vector<vector<int>> ans = a;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int d = 0;

            if (i < m - 1)
            {
                if (a[i + 1][j] == 1)
                {
                    d++;
                }
            }

            if (i > 0)
            {
                if (a[i - 1][j] == 1)
                {
                    d++;
                }
            }

            if (j < n - 1)
            {
                if (a[i][j + 1] == 1)
                {
                    d++;
                }
            }

            if (j > 0)
            {
                if (a[i][j - 1] == 1)
                {
                    d++;
                }
            }

            if (j > 0 && i > 0)
            {
                if (a[i - 1][j - 1] == 1)
                {
                    d++;
                }
            }

            if (j < n - 1 && i < m - 1)
            {
                if (a[i + 1][j + 1] == 1)
                {
                    d++;
                }
            }

            if (j < n - 1 && i > 0)
            {
                if (a[i - 1][j + 1] == 1)
                {
                    d++;
                }
            }

            if (j > 0 && i < m - 1)
            {
                if (a[i + 1][j - 1] == 1)
                {
                    d++;
                }
            }

            if (a[i][j] == 1)
            {
                if (d < 2)
                {
                    ans[i][j] = 0;
                }
                else if (d == 2 || d == 3)
                {
                    ans[i][j] = 1;
                }
                else if (d > 3)
                {
                    ans[i][j] = 0;
                }
            }
            else if (a[i][j] == 0)
            {
                if (d == 3)
                {
                    ans[i][j] = 1;
                }
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = ans[i][j];
        }
    }
}

int main()
{

    return 0;
}
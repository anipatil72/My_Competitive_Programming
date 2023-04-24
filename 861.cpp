// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;
using namespace __gnu_pbds;

int recur(int fir, int sec, string &a, string &b, vector<vector<int>> &dp)
{
    if (sec < 0)
    {
        return fir + 1;
    }

    if (fir < 0)
    {
        return sec + 1;
    }

    if (dp[fir][sec] != -1)
    {
        return dp[fir][sec];
    }

    if (a[fir] == b[sec])
    {
        return recur(fir - 1, sec - 1, a, b, dp);
    }

    int del = 1 + recur(fir - 1, sec, a, b, dp);

    int ins = 1 + recur(fir, sec - 1, a, b, dp);

    int replace = 1 + recur(fir - 1, sec - 1, a, b, dp);

    return dp[fir][sec] = min({del, ins, replace});
}

int editDistanceTabulation(string &a, string &b)
{
    int n = a.length();

    int m = b.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = i;
    }

    for (int i = 1; i <= m; i++)
    {
        dp[0][i] = i;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
            }
        }
    }

    string ans = a;

    int row = n, col = m;

    while (row > 0 && col > 0)
    {

        if (a[row - 1] == b[col - 1])
        {
            cout << "At row : " << row << " and col : " << col << " doing nothing " << endl;
            row--;

            col--;
        }
        else
        {
            int tem = min({dp[row - 1][col], dp[row][col - 1], dp[row - 1][col - 1]});

            if (tem == dp[row - 1][col])
            {
                cout << "At row : " << row << " and col : " << col << " deleting the current character in a " << endl;

                if ((ans.begin() + row - 1) != ans.end())
                {
                    ans.erase(ans.begin() + row - 1);
                }
                else
                {
                    cout << "Some thing went wrong in delete operation!" << endl;
                }

                row--;
            }
            else if (tem == dp[row][col - 1])
            {
                ans.insert(ans.begin() + row, b[col - 1]);
                cout << "At row : " << row << " and col : " << col << " inserting the current character of b in a " << endl;

                col--;
            }
            else
            {
                cout << "At row : " << row << " and col : " << col << " replacing the current character of a same as in b " << endl;

                ans[row - 1] = b[col - 1];

                row--;

                col--;
            }
        }

        cout << "This is ans after current opertaion : " << ans << endl;
    }

    while (row > 0)
    {
        cout << "At row : " << row << " and col : " << col << " deleting the current character in a " << endl;
        ans.erase(ans.begin() + row - 1);

        cout << "This is ans after current opertaion : " << ans << endl;

        row--;
    }

    while (col > 0)
    {
        ans.insert(ans.begin() + row, b[col - 1]);
        cout << "At row : " << row << " and col : " << col << " inserting the current character of b in a " << endl;

        cout << "This is ans after current opertaion : " << ans << endl;

        col--;
    }

    return dp[n][m];
}

int editDistance(string a, string b)
{
    int n = a.length();

    int m = b.length();

    vector<vector<int>> dp(n, vector<int>(m, -1));

    return recur(n - 1, m - 1, a, b, dp);
}

int main()
{

    string a = "newbie";

    string b = "expert";

    cout << editDistanceTabulation(a, b) << endl;

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
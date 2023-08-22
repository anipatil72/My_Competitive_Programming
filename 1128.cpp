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

void pressit(vector<vector<int>> &mat, vector<vector<string>> &ans)
{

    int n = mat.size();

    vector<string> dess;

    int tot = 0;

    for (int i = 0; i < n; i++)
    {
        string des = "";

        for (int j = 0; j < n; j++)
        {
            des += (mat[i][j] == 1) ? 'Q' : '.';

            tot += mat[i][j];
        }

        dess.push_back(des);
    }

    if (n == tot)
    {
        ans.push_back(dess);
    }

    // return dess;
}

bool check(int row, int col, vector<vector<int>> &mat)
{
    int n = mat.size();

    int t;

    t = row;

    while (t >= 0)
    {
        if (mat[t][col] == 1)
        {
            return false;
        }

        t--;
    }

    t = col;
    while (t >= 0)
    {
        if (mat[row][t] == 1)
        {
            return false;
        }

        t--;
    }

    t = row;

    while (t < n)
    {
        if (mat[t][col] == 1)
        {
            return false;
        }

        t++;
    }

    t = col;
    while (t < n)
    {
        if (mat[row][t] == 1)
        {
            return false;
        }

        t++;
    }

    int i = row, j = col;

    while (i >= 0 && j >= 0)
    {
        if (mat[i][j] == 1)
        {
            return false;
        }

        i--;
        j--;
    }

    i = row;
    j = col;

    while (i < n && j < n)
    {
        if (mat[i][j] == 1)
        {
            return false;
        }

        i++;
        j++;
    }

    i = row;
    j = col;

    while (i >= 0 && j < n)
    {
        if (mat[i][j] == 1)
        {
            return false;
        }

        i--;
        j++;
    }

    i = row;
    j = col;

    while (i < n && j >= 0)
    {
        if (mat[i][j] == 1)
        {
            return false;
        }

        i++;
        j--;
    }

    return true;
}

void recur(int row, vector<vector<int>> &mat, vector<vector<string>> &ans)
{

    int n = mat.size();

    if (row == n)
    {
        // ans.push_back(pressit(mat));

        pressit(mat, ans);

        return;
    }

    for (int i = row; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (check(i, j, mat))
            {
                mat[i][j] = 1;

                recur(i + 1, mat, ans);

                mat[i][j] = 0;
            }
        }
    }
}

vector<vector<string>> nqueens(int n)
{

    if (n <= 2)
    {
        return {};
    }

    vector<vector<int>> mat(n, vector<int>(n, 0));

    vector<vector<string>> ans;

    recur(0, mat, ans);

    return ans;
}

int main()
{

    int n = 8;

    vector<vector<string>> ans = nqueens(n);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << endl;
        }

        cout << endl;
        cout << endl;
    }

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
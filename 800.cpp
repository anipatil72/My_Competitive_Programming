// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;

template <typename T_vector>
void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1)
{
    if (start < 0)
    {
        start = 0;
    }
    if (end < 0)
    {
        end = int(v.size());
    }

    for (int i = start; i < end; i++)
    {
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
    }
}

int ide(int i, int j, int n)
{
    int id = n * i + j;

    return id;
}

vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators)
{
    int ops = 0;

    int k = operators.size();

    vector<int> ans(k);

    vector<vector<int>> mat(n, vector<int>(m, 0));

    for (int i = 0; i < k; i++)
    {
        int row = operators[i][0], col = operators[i][1];

        int con = 0;

        if (row > 0)
        {
            con += (mat[row - 1][col] == 1);
        }

        if (row < n - 1)
        {
            con += (mat[row + 1][col] == 1);
        }

        if (col > 0)
        {
            con += (mat[row][col - 1] == 1);
        }

        if (col < m - 1)
        {
            con += (mat[row][col + 1] == 1);
        }

        if (con == 0)
        {
            ops++;
        }
        else
        {

            ops -= (con - 1);
        }

        ans[i] = ops;

        mat[row][col] = 1;
    }

    return ans;
}

int main()
{

    int n = 4, m = 5;

    vector<vector<int>> opss = {{1, 1}, {0, 1}, {3, 3}, {3, 4}};

    vector<int> ans = numOfIslands(n, m, opss);

    output_vector(ans);

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
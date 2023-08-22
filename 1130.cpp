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

bool isValid(int row, int col, vector<vector<int>> &mat)
{
    int n = mat.size();

    int m = mat[0].size();

    if (row >= 0 && row < n && col >= 0 && col < m)
    {
        return true;
    }

    return false;
}

int Count(vector<vector<int>> &matrix)
{

    int n = matrix.size();

    int m = matrix[0].size();

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            if (matrix[i][j] == 1)
            {
                int tem = 0;

                if (isValid(i - 1, j, matrix) && matrix[i - 1][j] == 0)
                {
                    tem++;
                }

                if (isValid(i, j - 1, matrix) && matrix[i][j - 1] == 0)
                {
                    tem++;
                }

                if (isValid(i + 1, j, matrix) && matrix[i + 1][j] == 0)
                {
                    tem++;
                }

                if (isValid(i, j + 1, matrix) && matrix[i][j + 1] == 0)
                {
                    tem++;
                }

                if (isValid(i - 1, j - 1, matrix) && matrix[i - 1][j - 1] == 0)
                {
                    tem++;
                }

                if (isValid(i - 1, j + 1, matrix) && matrix[i - 1][j + 1] == 0)
                {
                    tem++;
                }

                if (isValid(i + 1, j + 1, matrix) && matrix[i + 1][j + 1] == 0)
                {
                    tem++;
                }

                if (isValid(i + 1, j - 1, matrix) && matrix[i + 1][j - 1] == 0)
                {
                    tem++;
                }

                if (tem % 2 == 0)
                {
                    ans++;
                }
            }
        }
    }

    return ans;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
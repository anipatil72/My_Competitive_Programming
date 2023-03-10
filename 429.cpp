#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> spiralOrder(int n)
{

    vector<vector<int>> matrix(n, vector<int>(n, 0));

    // int n = matrix.size();
    int m = matrix[0].size();

    int tot = n * n;

    // vector<int>v;

    int up = 0, down = n - 1, left = 0, right = m - 1;
    int k = 1;

    while (left <= right && up <= down && k < tot)
    {
        for (int i = left; i <= right && k <= tot; i++)
        {
            // v.push_back(matrix[up][i]);

            // matrix[up]

            matrix[up][i] = k;

            k++;
        }

        up++;

        for (int i = up; i <= down && k <= tot; i++)
        {
            // v.push_back(matrix[i][right]);
            matrix[i][right] = k;
            k++;
        }

        right--;

        for (int i = right; i >= left && k <= tot; i--)
        {
            // v.push_back(matrix[down][i]);
            matrix[down][i] = k;
            k++;
        }

        down--;

        for (int i = down; i >= up && k <= tot; i--)
        {

            // v.push_back(matrix[i][left]);
            matrix[i][left] = k;
            k++;
        }

        left++;
    }

    return matrix;
}

int main()
{

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> diagonalSort(vector<vector<int>> &mat)
{
    int m = mat.size();

    int n = mat[0].size();

    for (int i = 0; i < m; i++)
    {
        vector<int> v;

        int j = i, k = 0;

        while (j < m && k < n)
        {
            v.push_back(mat[j][k]);

            j++;
            k++;
        }

        sort(v.begin(), v.end());

        j = i, k = 0;

        int count = 0;

        while (j < m && k < n)
        {
            // v.push_back(mat[j][k]);

            mat[j][k] = v[count];

            count++;

            j++;
            k++;
        }
    }


    for (int i = 1; i < n; i++)
    {
        vector<int> v;

        int j = 0, k = i;

        while (j < m && k < n)
        {
            v.push_back(mat[j][k]);

            j++;
            k++;
        }

        sort(v.begin(), v.end());

        j = 0, k = i;

        int count = 0;

        while (j < m && k < n)
        {
            // v.push_back(mat[j][k]);

            mat[j][k] = v[count];

            count++;

            j++;
            k++;
        }
    }

    return mat;
}

int main()
{

    return 0;
}
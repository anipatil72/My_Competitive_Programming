#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{

    int n = matrix.size();

    int m = matrix[0].size();

    for (int i = 0; i < n; i++)
    {
        if (matrix[i][m - 1] >= target)
        {
            if (binary_search(matrix[i].begin(), matrix[i].end(), target))
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{

    vector<vector<int>> m = {{1,4,7,11,15},
                             {2,5,8,12,19},
                             {3,6,9,16,22},
                             {10,13,14,17,24},
                             {18,21,23,26,30}};


    cout<<searchMatrix(m,101);                       

    return 0;
}
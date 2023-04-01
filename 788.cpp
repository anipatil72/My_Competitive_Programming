// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

// The Floyd Warshall Algorithm

void shortest_distance(vector<vector<int>> &matrix)
{
    int n = matrix.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == -1)
            {
                matrix[i][j] = int(1e9);
            }

            if (i == j)
            {
                matrix[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {

                matrix[i][j] = min(matrix[j][k], matrix[j][i] + matrix[i][k]);
            }
        }
    }

    // For finding if there is a negative edge cycle or not

    bool is_negative_cycle = false;

    for (int i = 0; i < n; i++)
    {
        if (matrix[i][i] < 0)
        {
            // There is teh negative edge cycle

            is_negative_cycle = true;
        }
    }

    

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == int(1e9))
            {
                matrix[i][j] = -1;
            }

            if (i == j)
            {
                matrix[i][j] = 0;
            }
        }
    }
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
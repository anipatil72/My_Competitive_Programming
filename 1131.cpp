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

int findMinOpeartion(vector<vector<int>> matrix, int n)
{
    vector<vector<int>> ans = matrix;

    vector<int> col(n);

    vector<int> row(n);

    int maxi = 0;

    for (int i = 0; i < n; i++)
    {
        int sum = 0;

        for (int j = 0; j < n; j++)
        {
            sum += (ans[j][i]);
        }

        col[i] = sum;

        maxi = max(maxi, sum);
    }

    for (int i = 0; i < n; i++)
    {
        int sum = 0;

        for (int j = 0; j < n; j++)
        {
            sum += (ans[i][j]);
        }

        col[i] = sum;
        maxi = max(maxi, sum);
    }

    int a = 0, b = 0;

    int ops = 0;

    while (a < n && b < n)
    {
        if (row[a] > col[b])
        {
            int left = maxi - row[a];

            if (left > 0)
            {
                ops += left;
            }

            row[a] += left;

            col[b] += left;

            a++;
        }
        else if (row[a] < col[b])
        {
            int left = maxi - col[b];

            if (left > 0)
            {
                ops += left;
            }

            row[a] += left;

            col[b] += left;

            b++;
        }
        else
        {
            int left = maxi - col[b];

            if (left > 0)
            {
                ops += left;
            }

            row[a] += left;

            col[b] += left;

            a++;

            b++;
        }
    }

    return ops;
}

int main()
{

    vector<vector<int>> mat = {{1, 2, 3},
                               {4, 2, 3},
                               {3, 2, 1}};

    int n = mat.size();

    cout << findMinOpeartion(mat, n) << endl;

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
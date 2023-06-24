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

int recur(int index, int prev, int arr[], int n, vector<vector<int>> &dp)
{
    if (index < 0)
    {
        return 0;
    }

    if (dp[index][prev] != -1)
    {
        return dp[index][prev];
    }

    int inc = 0, exc = 0;

    if (prev == 0 || (arr[index] < arr[prev - 1]))
    {
        inc = 1 + recur(index - 1, index + 1, arr, n, dp);
    }

    exc = recur(index - 1, prev, arr, n, dp);

    return dp[index][prev] = max(inc, exc);
}

template <typename T_vector>
void print_2D(vector<T_vector> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

int longestIncreasingSubsequence(int arr[], int n)
{

    // vector<vector<int>> dp(n + 1, vector<int>(n + 2, 0));

    vector<int> cur(n + 2, 0);
    vector<int> prev(n + 2, 0);

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            int inc = 0, exc = 0;

            if (j == 0 || (arr[i - 1] < arr[j - 1]))
            {
                inc = 1 + prev[i];
            }

            exc = prev[j];

            cur[j] = max(inc, exc);
        }

        prev = cur;
    }

    // print_2D(dp);

    return prev[0];
}

int main()
{

    int test[] = {5, 4, 11, 1, 16, 18};

    cout << longestIncreasingSubsequence(test, 6);

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
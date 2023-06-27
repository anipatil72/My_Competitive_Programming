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

int recur(int index, int jindex, int arr[], vector<vector<int>> &dp)
{

    // cout << "I am here : " << index << " " << jindex << endl;
    if (index == jindex || (index + 1 == jindex))
    {
        return 0;
    }

    if (dp[index][jindex] != -1)
    {
        return dp[index][jindex];
    }

    int tem = 1e9;

    for (int i = index + 1; i < jindex; i++)
    {
        int des = arr[index] * arr[i] * arr[jindex] + recur(index, i, arr, dp) + recur(i, jindex, arr, dp);

        tem = min(tem, des);
    }

    // cout << endl;

    // print_2D(dp);

    // cout << endl;

    return dp[index][jindex] = tem;
}

int matrixChainMultiplication(int n, int arr[])
{
    vector<vector<int>> dp(n, vector<int>(n, -1));

    return recur(0, n - 1, arr, dp);

    // // print_2D(dp);

    // return ans;
}

int main()
{

    int arr[] = {10, 30, 5, 60};

    int n = sizeof(arr) / (sizeof(arr[0]));

    cout << matrixChainMultiplication(n, arr);

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
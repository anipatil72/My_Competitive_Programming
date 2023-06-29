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

int recur(int index, int jindex, vector<int> &cuts, vector<vector<int>> &dp)
{
    int n = cuts.size();

    if (index > jindex)
    {
        return 0;
    }

    if (dp[index][jindex] != -1)
    {
        return dp[index][jindex];
    }

    int tem = 1e9;

    for (int i = index; i <= jindex; i++)
    {
        int des = cuts[jindex + 1] - cuts[index - 1] + recur(index, i - 1, cuts, dp) + recur(i + 1, jindex, cuts, dp);

        tem = min(tem, des);
    }

    return dp[index][jindex] = tem;
}

int cost(int n, int c, vector<int> &cuts)
{
    cuts.push_back(n);

    cuts.push_back(0);

    sort(cuts.begin(), cuts.end());

    vector<vector<int>> dp(c + 2, vector<int>(c + 2, 0));

    // for (int i = 1; i <= c; i++)
    // {
    //     dp[i][i] = cuts[i + 1] - cuts[i - 1];
    // }

    for (int i = c; i >= 1; i--)
    {

        for (int j = i; j <= c; j++)
        {
            int tem = 1e9;

            for (int k = i; k <= j; k++)
            {
                int des = cuts[j + 1] - cuts[i - 1] + dp[i][k - 1] + dp[k + 1][j];

                tem = min(tem, des);
            }

            if (tem != (int)(1e9))
            {
                dp[i][j] = tem;
            }
        }
    }

    print_2D(dp);

    return dp[1][c];

    // int ans = recur(1, c, cuts, dp);

    // print_2D(dp);

    // return ans;
}

int main()
{

    vector<int> cust = {1, 3};

    int n = 10, c = 2;

    cout << cost(n, c, cust);

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
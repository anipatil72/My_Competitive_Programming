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

int maxCoins(vector<int> &a)
{
    int n = a.size();

    // a.push_back(1);

    // a.insert(a.begin(), 1);

    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Balllons will go from 1 to n ;

    for (int i = 0; i < n; i++)
    {
        dp[i][i] = 0;

        int left = 1, right = 1, center = a[i];

        if (i > 0)
        {
            left = a[i - 1];
        }

        if (i < n - 1)
        {
            right = a[i + 1];
        }

        dp[i][i] = left * 1LL * right * center;
    }

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i; j < n; j++)
        {

            if (i == j)
            {
            }
            else
            {
                long long tem = 0;

                for (int k = i; k <= j; k++)
                {

                    long long des = 0, left = 1, right = 1, center = a[k];

                    if (k > i)
                    {
                        des += dp[i][k - 1];

                        left = a[k - 1];
                    }

                    if (k < j)
                    {
                        des += dp[k + 1][j];

                        right = a[k + 1];
                    }

                    des += (left * right * center);

                    tem = max(des, tem);
                }

                dp[i][j] = tem;
            }
        }
    }

    print_2D(dp);

    return dp[0][n - 1];
}

int main()
{

    vector<int> test = {7, 1, 8};

    cout << maxCoins(test);

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
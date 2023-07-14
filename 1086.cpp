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

int superEggDrop(int k, int n)
{

    // recur(f, 1) = f;
    // recur(0, e) = 0
    // recur(1, e) = 1

    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

    for (int i = 1; i <= n; i++)
    {

        dp[i][1] = i;
    }

    for (int i = 1; i <= k; i++)
    {
        dp[1][i] = 1;
    }

    // print_2D(dp);

    for (int i = 2; i <= n; i++)
    {
        for (int j = 2; j <= k; j++)
        {
            int ans = 1e9;

            for (int tem = 1; tem <= i; tem++)
            {
                ans = min(ans, 1 + max(dp[tem - 1][j - 1], dp[i - tem][j]));
            }

            dp[i][j] = ans;
        }
    }

    // print_2D(dp);

    return dp[n][k];
}

int main()
{

    int floors = 1, eggs = 2;

    cout << superEggDrop(eggs, floors);

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
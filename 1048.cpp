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
bool isPalindrome(string &s, int index, int jindex)
{

    while (index < jindex)
    {
        if (s[index] != s[jindex])
        {
            return false;
        }

        index++;

        jindex--;
    }

    return true;
}

int recur(int index, string &s, vector<int> &dp)
{
    int n = s.length();

    if (index >= n)
    {
        return 0;
    }

    if (dp[index] != -1)
    {
        return dp[index];
    }

    int ans = n - 1;

    int dex = -1;

    for (int i = index; i < n; i++)
    {
        if (isPalindrome(s, index, i))
        {
            int des = recur(i + 1, s, dp);

            if (i == n - 1)
            {
                des = 0;
            }
            else
            {
                des += 1;
            }

            ans = min(ans, des);

            // if (ans > des)
            // {
            //     ans = des;

            //     dex = i;
            // }
        }
    }

    // cout << "Minimum Partition for index = " << index << " and for jindex = " << jindex << endl;

    // cout << dex << endl;

    return dp[index] = ans;
}

int minCut(string s)
{
    int n = s.length();

    // if (n == 1)
    // {
    //     return 0;
    // }

    vector<int> dp(n, -1);

    return recur(0, s, dp);
}

int main()
{
    string s = "BABABCBADCEDE";

    cout << minCut(s) << endl;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
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

int recur(int index, string &s, string tem, unordered_set<string> &m, vector<int> &dp)
{
    int n = s.length();

    if (index == n)
    {
        if (m.count(tem) > 0 || tem == "")
        {
            return true;
        }

        return false;
    }

    if (dp[index] != -1)
    {
        return dp[index];
    }

    int ans = 0;

    for (int i = index; i < n; i++)
    {
        tem += s[i];

        if (m.count(tem) > 0)
        {
            string des = "";

            int check = recur(i + 1, s, des, m, dp);

            if (check == 1)
            {
                ans = 1;
            }
        }
    }

    return dp[index] = ans;
}

// Done

bool wordBreak(string s, vector<string> &wordDict)
{
    int n = s.length();

    unordered_set<string> m;

    int len = wordDict.size();

    for (int i = 0; i < len; i++)
    {
        m.insert(wordDict[i]);
    }

    vector<int> dp(n, -1);

    string tem = "";

    int ans = recur(0, s, tem, m, dp);

    return ans == 1;
}

int main()
{

    string s = "catsandog";

    vector<string> wordDict = {"cats", "dog", "sand", "and", "cat"};

    cout << wordBreak(s, wordDict) << endl;
    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
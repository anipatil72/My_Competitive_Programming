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

bool myComp(string &a, string &b)
{
    int aa = a.length(), bb = b.length();

    return aa < bb;
}

bool check(string &a, string &b)
{
    int aa = a.length(), bb = b.length();

    if (bb - aa != 1)
    {
        return false;
    }

    string tem = a;

    int pos = 0;

    bool des = 1;

    while (pos < aa)
    {
        if (b[pos] != a[pos])
        {
            tem.insert(tem.begin() + pos, b[pos]);

            des = 0;

            break;
        }
    }

    if (des)
    {
        tem.insert(tem.begin() + pos, b[pos]);

        des = 0;
    }

    return tem == b;
}

int longestStrChain(vector<string> &words)
{
    int n = words.size();

    sort(words.begin(), words.end(), myComp);

    vector<int> dp(n);

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        int men = 0;

        for (int j = 0; j < i; j++)
        {
            if (check(words[j], words[i]))
            {
                men = max(men, dp[j]);
            }
        }

        dp[i] = 1 + men;

        ans = max(ans, dp[i]);
    }

    return ans;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
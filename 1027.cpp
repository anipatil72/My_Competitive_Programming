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

bool check(string a, string b)
{
    int n = a.length();

    int m = b.length();

    int pa = 0, pb = 0;

    int count = 0;

    while (pa < n && pb < m)
    {
        if (a[pa] != b[pb])
        {
            count++;

            if (count >= 2)
            {
                return false;
            }

            pb++;
        }
        else
        {
            pa++;

            pb++;
        }
    }

    if (pa == n && pb == m)
    {
        return true;
    }

    if (pa == n && pb + 1 == m)
    {
        return true;
    }

    // vector<int> fa(26, 0);
    // vector<int> fb(26, 0);

    // for (int i = 0; i < n; i++)
    // {
    //     fa[a[i] - 'a']++;
    // }

    // for (int i = 0; i < m; i++)
    // {
    //     fb[b[i] - 'a']++;
    // }

    // int sum = 0;

    // int index = -1;

    // for (int i = 0; i < 26; i++)
    // {
    //     fa[i] -= fb[i];

    //     fa[i] = abs(fa[i]);

    //     if (fa[i] == 1)
    //     {
    //         index = i;
    //     }

    //     sum += fa[i];
    // }

    // if (sum != 1)
    // {
    //     return false;
    // }

    // char d = (char)('a' + index);

    // for (int i = 0; i < m; i++)
    // {
    //     string tem = b;

    //     if (d == tem[i])
    //     {
    //         tem.erase(tem.begin() + i);

    //         if (tem == a)
    //         {
    //             return true;
    //         }
    //     }
    // }

    return false;
}

bool myComp(string &a, string &b)
{
    return a.length() < b.length();
}

int longestStrChain(vector<string> &words)
{
    int n = words.size();

    sort(words.begin(), words.end(), myComp);

    vector<int> dp(n, 1);

    int ans = 1;

    for (int i = 0; i < n; i++)
    {
        int tem = 0;
        for (int j = 0; j < i; j++)
        {
            if (check(words[j], words[i]))
            {
                tem = max(tem, dp[j]);
            }
        }

        dp[i] = 1 + tem;

        ans = max(ans, dp[i]);
    }

    return ans;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
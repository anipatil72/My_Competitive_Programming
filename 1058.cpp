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

bool buddyStrings(string s, string goal)
{
    int n = s.length();

    int m = goal.length();

    if (m != n)
    {
        return false;
    }

    int index = -1;

    vector<int> fos(26, 0);

    bool flag = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] != goal[i])
        {
            if (index == -1)
            {
                index = i;
            }
            else
            {
                swap(s[index], s[i]);

                return (s == goal);
            }
        }

        fos[s[i] - 'a']++;

        if (fos[s[i] - 'a'] >= 2)
        {
            flag = true;
        }
    }

    if (flag && index == -1)
    {
        return true;
    }

    return false;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
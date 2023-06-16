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

bool myComp(pair<int, int> &a, pair<int, int> &b)
{
    return a.second > b.second;
}

bool check(string s, int k)
{
    int n = s.length();

    vector<int> p(26, -1);

    for (int i = 0; i < n; i++)
    {
        if (p[s[i] - 'a'] == -1)
        {
            p[s[i] - 'a'] = i;
        }
        else
        {
            if ((i - p[s[i] - 'a']) < k)
            {
                return false;
            }
            else
            {

                p[s[i] - 'a'] = i;
            }
        }
    }

    return true;
}

string rearrangeString(string &s, int k)
{
    int n = s.length();

    if (k == 1 || n == 1)
    {
        return s;
    }

    unordered_map<int, int> freq;

    int mini = n + 1;

    for (int i = 0; i < n; i++)
    {
        freq[s[i] - 'a']++;

        // mini = min(mini, freq[s[i] - 'a']);
    }

    if (freq.size() < k)
    {
        return "";
    }

    vector<pair<int, int>> tem(freq.begin(), freq.end());

    sort(tem.begin(), tem.end(), myComp);

    int pos = k;

    string ans = "";

    int poin = 0;
    int len = tem.size();

    while ((pos < len) && (ans.size() < n))
    {
        if (tem[poin].second == 0)
        {
            tem[poin] = tem[pos++];
        }

        char d = 'a' + tem[poin].first;

        tem[poin].second--;

        ans += d;

        poin++;

        if (poin == k)
        {
            poin = 0;
        }
    }

    while (ans.size() < n)
    {
        if (tem[poin].second == 0)
        {
            poin++;

            if (poin == k)
            {
                poin = 0;
            }

            continue;
        }

        char d = 'a' + tem[poin].first;

        tem[poin].second--;

        ans += d;

        poin++;

        if (poin == k)
        {
            poin = 0;
        }
    }

    cout << ans << endl;

    if (check(ans, k))
    {
        return ans;
    }

    return "";
}

int main()
{

    string test = "bbabcaccaaabababbaaaaccbbcbacbacacccbbcaabcbcacaaccbabbbbbcacccaccbabaccbacabcabcacb";

    cout << rearrangeString(test, 2) << endl;

    return 0;
}

// "cacabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabc"

// ॥ जय श्री राम जय श्री कृष्ण ॥
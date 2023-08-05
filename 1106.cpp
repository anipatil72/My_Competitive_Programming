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

void recur(int index, vector<string> &ans, string des, string cur, string &s, unordered_set<string> &m)
{
    int n = s.length();

    if (index == n)
    {
        if (cur == "")
        {
            ans.push_back(des);
        }
    }

    for (int i = index; i < n; i++)
    {
        cur += s[i];

        if (m.count(cur) > 0)
        {
            // string des = "";

            string temp = des;

            if (des != "")
            {
                temp += ' ';
            }

            temp += cur;

            string tur = "";

            recur(i + 1, ans, temp, tur, s, m);
        }
    }
}

vector<string> wordBreak(string s, vector<string> &wordDict)
{
    int n = s.length();

    int len = wordDict.size();

    unordered_set<string> m;

    for (int i = 0; i < len; i++)
    {
        m.insert(wordDict[i]);
    }

    vector<string> ans;

    string org = "";

    recur(0, ans, org, org, s, m);

    return ans;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
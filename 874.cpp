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

bool myComp(pair<int, pair<int, int>> &a, pair<int, pair<int, int>> &b)
{

    return a.first < b.first && a.second.first < b.second.second;
}

string removeDuplicateLetters(string s)
{
    int n = s.length();

    unordered_map<int, pair<int, int>> m;

    for (int i = 0; i < n; i++)
    {
        if (m.count(s[i] - 'a') == 0)
        {
            m[s[i] - 'a'].first = i;
            m[s[i] - 'a'].second = i;
        }
        else
        {

            m[s[i] - 'a'].second = i;
        }
    }

    vector<pair<int, pair<int, int>>> pos(m.begin(), m.end());

    sort(pos.begin(), pos.end(), myComp);

    string ans = "";

    int len = pos.size();

    for (int i = 0; i < len; i++)
    {
        char d = 'a' + pos[i].first;

        ans += d;
    }

    return ans;
}

int main()
{
    string test = "cbacdcbc";

    cout << removeDuplicateLetters(test) << endl;

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
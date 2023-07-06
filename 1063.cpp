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

        index++, jindex--;
    }

    return true;
}

void recur(int index, string &s, vector<vector<string>> &ans, vector<string> &temp)
{
    int n = s.length();

    if (index == n)
    {
        ans.push_back(temp);

        return;
    }

    for (int i = index; i < n; i++)
    {
        if (isPalindrome(s, index, i))
        {
            string des = s.substr(index, i - index + 1);

            temp.push_back(des);

            recur(i + 1, s, ans, temp);

            temp.pop_back();
        }
    }
}

vector<vector<string>> partition(string s)
{
    int n = s.length();

    vector<vector<string>> ans;

    vector<string> tem;

    recur(0, s, ans, tem);

    return ans;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
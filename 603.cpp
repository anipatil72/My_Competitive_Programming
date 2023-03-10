#include <bits/stdc++.h>
using namespace std;

bool isSubsequence(string s, string t)
{
    int n = t.length();

    int m = s.length();

    vector<int> f(26, 0);

    for (int i = 0; i < n; i++)
    {
        f[t[i] - 'a']++;
    }

    for (int i = 0; i < m; i++)
    {
        f[s[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++)
    {
        if (f[i] < 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{

    // string a = "abc";

    // string b = "uibaibtvc";

    // cout<<is_permutation(b.begin(), b.end(),a.begin(), a.end());

    return 0;
}
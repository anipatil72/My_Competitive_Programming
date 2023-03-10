// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define M 1000000007
using namespace std;

// Google KickStart Problem
// KickStart 2022 : Round E , Problem C : Matching Palindrome

bool isPalindrome(string &s)
{
    int n = s.length();

    for (int i = 0; i < n / 2; i++)
    {
        if (s[i] != s[n - 1 - i])
        {
            return false;
        }
    }

    return true;
}

void solve()
{
    int n;

    cin >> n;

    string s;

    cin >> s;

    unordered_map<char, int> m;

    int minf = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        m[s[i]]++;
    }

    for (auto x : m)
    {
        minf = min(x.second, minf);
    }

    int req = n / minf;

    // cout << minf << endl;
    // cout << req << endl;

    string can = s.substr(0, req);

    string canbe = s.substr(req);

    // cout << can << endl;

    if (isPalindrome(can)&&isPalindrome(canbe))
    {
        cout << can << endl;
    }
    else
    {
        cout << s << endl;
    }
}

int main()
{

    int tt;

    cin >> tt;

    for (int i = 0; i < tt; i++)
    {
        // cout << "Case #" << (i + 1) << ": ";

        solve();

        // cout<<endl;
    }

    // string s = "abcdeefg";

    // string tem = s.substr(0, 4);

    // string temp = s.substr(4);

    // cout<<tem<<" "<<temp<<endl;

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
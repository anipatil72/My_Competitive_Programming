#include <iostream>
#include <string>
#include <vector>

#include <bits/stdc++.h>

using namespace std;

vector<int> computeLPSArray(const string &str)
{
    int n = str.size();
    vector<int> lps(n, 0);
    int len = 0;
    int i = 1;
    while (i < n)
    {
        if (str[i] == str[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

int minEraseToGood(const string &s)
{
    string reversed = s;
    reverse(reversed.begin(), reversed.end());
    string combined = s + reversed;

    vector<int> lps = computeLPSArray(combined);

    return s.length() - lps.back();
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << minEraseToGood(s) << "\n";
    }
    return 0;
}

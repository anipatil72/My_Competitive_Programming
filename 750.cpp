// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define M 1000000007
using namespace std;

bool checkInclusion(string s1, string s2)
{

    vector<int> ft(26, 0);
    vector<int> fp(26, 0);

    int n = s2.length();

    int pat = s1.length();

    if (n < pat)
    {
        return false;
    }

    if (n == pat)
    {
        sort(s2.begin(), s2.end());

        sort(s1.begin(), s1.end());

        return s1 == s2;
    }

    for (int i = 0; i < pat; i++)
    {
        fp[s1[i] - 'a']++;

        ft[s2[i] - 'a']++;
    }

    if (fp == ft)
    {
        cout<<0<<endl;
        return true;
    }

    for (int i = pat; i < n; i++)
    {
        ft[s2[i - pat] - 'a']--;

        ft[s2[i] - 'a']++;

        if ((ft[s2[i - pat] - 'a'] != fp[s2[i - pat] - 'a']) || (ft[s2[i] - 'a'] != fp[s2[i] - 'a']))
        {
            continue;
        }
        else if (fp == ft)
        {
            cout<<i<<endl;
            return true;
        }
    }

    return false;
}

int main()
{

    string s1 = "ab";

    string s2 = "eidbaooo";

    cout<<checkInclusion(s1,s2);

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
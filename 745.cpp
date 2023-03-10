// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define M 1000000007
using namespace std;

vector<int> LPS(string s)
{

    int n = s.length();

    vector<int> lps(n);

    lps[0] = 0;

    int len = 0;

    int i = 1;

    while (i < n)
    {
        if (s[len] == s[i])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
            else
            {
                len = lps[len - 1];
            }
        }
    }

    return lps;
}

vector<int> KMP(string &text, string &pattern)
{

    int n = text.length();
    int m = pattern.length();

    vector<int> ans;

    vector<int> lps = LPS(pattern);

    int i = 0, j = 0;

    while (i < n)
    {
        if (text[i] == pattern[j])
        {
            i++;
            j++;
        }

        if (j == m)
        {
            ans.push_back(i - j);
            j = lps[j - 1];
        }

        if (i < n && text[i] != pattern[j])
        {
            if (j == 0)
            {
                i++;
            }
            else
            {
                j = lps[j - 1];
            }
        }
    }

    return ans;
}

vector<int> ZAlgo(string text, string pat)
{

    string s = pat + "$" + text;

    int n = s.length();

    vector<int> z(n);

    int left = 0, right = 0;

    for (int i = 1; i < n; i++)
    {

        if (i > right)
        {
            left = right = i;

            while (s[right] == s[right - left])
            {
                right++;
            }

            z[i] = right - left;

            right--;
        }
        else
        {

            int k = i - left;
            if (i + z[k] <= right)
            {

                z[i] = z[k];
            }
            else
            {

                left = i;

                while (right < n && s[right - left] == s[right])
                {
                    right++;
                }

                z[i] = right - left;

                right--;
            }
        }
    }

    return z;
}

int main()
{

    string s = "abcaabhabcsa";

    string pat = "abc";

    vector<int> z = ZAlgo(s, pat);

    for (int i = 0; i < z.size(); i++)
    {
        if (z[i] == pat.size())
        {
            cout << "Found at : " << (i - pat.length() - 1) << "\n";
        }
    }

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥

// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;
using namespace __gnu_pbds;

bool recur(string &a, string &b, int fir, int sec)
{
    if (fir < 0)
    {
        if (sec >= 0)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    if (sec < 0)
    {
        return (fir == 0 && a[fir] == '*');
    }

    if (a[fir] == '?')
    {

        return recur(a, b, fir - 1, sec - 1);
    }
    else if (a[fir] == '*')
    {
        return recur(a, b, fir - 1, sec);
    }
    else if (a[fir] == b[sec])
    {

        return (recur(a, b, fir - 1, sec - 1) || recur(a, b, fir, sec - 1));
    }
    else
    {
    }
}

string helper(string &tem)
{
    string s = "";

    int len = tem.length();

    int pos = 0;

    while (pos < len)
    {
        if (tem[pos] == '*')
        {
            while (pos < len && tem[pos] == '*')
            {
                pos++;
            }

            s += '*';
        }
        else
        {
            s += tem[pos];

            pos++;
        }
    }

    // for (int i = 0; i < len; i++)
    // {

    //     if (tem[i] == '*')
    //     {
    //         // int pos = 0;

    //         while (i < len && tem[i] == '*')
    //         {
    //             i++;
    //         }

    //         s += '*';
    //     }
    //     else
    //     {
    //         s += tem[i];
    //     }
    // }

    return s;
}

bool wildcardMatching(string pattern, string text)
{
}

int main()
{

    string tem = "*";

    cout << helper(tem) << endl;

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
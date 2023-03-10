#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string &s)
{
    int n = s.length();

    for (int i = 0; i < n / 2; i++)
    {
        if (s[i] != s[n - 1 - i])
        {
            return 0;
        }
    }

    return 1;
}

int minChar(string pat)
{
    int M = pat.size();
    vector<int> lps(M);
    int len = 0;

    int m = 0 ;

    lps[0] = 0;
    int i = 1;
    while (i < M)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;

            m= max(len,m);
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
                m = max(len,m);
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    return m;
}

int Solution ::solve(string A)
{

    int n = A.size();


    if (n%2==1&&isPalindrome(A))
    {
            return 1;
    }


    string h = A ;

    reverse(h.begin(),h.end());


    string res = A + "$" + h ;

    // cout<<res<<endl;
    

    
    

    int p  = minChar(res);

    // cout<<p<<endl;

    string s = A;

    s.erase(s.begin() + p);

    string r = A;

    r.erase(r.end() - p - 1);

    // cout<<r<<endl;

    if (isPalindrome(s) || isPalindrome(r))
    {
        return 1;
    }

    return 0;
}

int main()
{


    string s =  "ivwvi";

    cout<<solve(s)<<endl;

    return 0;
}
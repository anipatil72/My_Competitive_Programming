#include <bits/stdc++.h>
using namespace std;

char findTheDifference(string s, string t)
{
    int n = s.length();

    vector<int> f(26, 0);

    for (int i = 0; i < n; i++)
    {
            f[s[i] - 'a']++;
    }

    for (int i = 0; i < n + 1; i++)
    {
            f[t[i]- 'a']--;
    }

    for (int i = 0; i < 26; i++)
    {
        if (f[i]==-1)
        {
                return 'a' + i;
        }
             
    }

    return 'a';
    
    
    
}

int main()
{

    string s = "abcd";

    string t = "abcde";

    // char d = t - s;

    char ti = 'a';

    char b = 'a' + 4;

    cout<<b<<endl;

    return 0;
}
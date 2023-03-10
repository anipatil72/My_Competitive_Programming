#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t)
{

    vector<int> scat(26,0);
    vector<int> tcat(26,0);

    for (int i = 0; i < s.length(); i++)
    {
            scat[s[i]-'a']++;
    }


    for (int i = 0; i < t.length(); i++)
    {
            tcat[t[i]-'a']++;
    }

    for (int i = 0; i < 26; i++)
    {
        if (scat[i]!=tcat[i])
        {
                return false;
        }
        
    }
    
    return true;

}

int main()
{

    return 0;
}
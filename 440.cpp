#include <bits/stdc++.h>
using namespace std;

int firstUniqChar(string s)
{

    int  v[26][2] = {0};

    int ans =  INT_MAX;

    int n = s.length();

    for (int i = 0; i<n ; i++)
    {

        if (v[s[i]-'a'][0]==0)
        {
            v[s[i]-'a'][1] = i;
        }
        

        v[s[i]-'a'][0]++;

    }

    for (int i = 0; i < 26; i++)
    {

        if (v[i][0]==1)
        {
             ans = min(ans,v[i][1]);   
        }
        
        
    }


    

    return ans==INT_MAX?-1:ans;
    
}

int main()
{

    return 0;
}
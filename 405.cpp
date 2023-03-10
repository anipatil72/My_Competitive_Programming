#include <bits/stdc++.h>
using namespace std;

int main() 
{

    string s;

    cin>>s;

    int n = s.length();

    string ans = "";

    // 0 is .
    // 1 is -.
    // 2 is --

    for (int i = 0; i < n; i++)
    {

        if (s[i]=='.')
        {
            ans+="0";
               
        }
        else if ((i<n-1)&&s[i]=='-'&&s[i+1]=='.')
        {
            ans+="1";
            i++;  
               
        }
        else if ((i<n-1)&&(s[i]=='-')&&s[i+1]=='-')
        {
             ans+="2";
             i++;   
        }
        
        
        
            
    }

    cout<<ans<<endl;
    

return 0;
}
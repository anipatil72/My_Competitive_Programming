#include <bits/stdc++.h>
using namespace std;

void solve(string s)
{
    int n = s.length();

    string ans = "";

    for (int i = 0; i < n; i++)
    {
            if (s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='y'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'||s[i]=='Y')
            {
                
            }
            else if (s[i]>='A'&&s[i]<='Z')
            {
                char c = s[i]+32;

                ans+='.';
                ans+=c;
            }
            else
            {
                ans+='.';
                ans+=s[i];
            }
            
            
            
    }


    cout<<ans;
    
}

int main()
{

    string s;

    cin >> s;

    solve(s);

    return 0;
}
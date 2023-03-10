#include <bits/stdc++.h>
using namespace std;

int main() 
{

    string s;

    cin>>s;


    int n = s.length();

    unordered_map<char,int> m;

    for (int i = 0; i < n; i++)
    {
            m[s[i]]++;
    }


    if (m.size()%2==1)
    {
            cout<<"IGNORE HIM!"<<endl;
    }
    else
    {
        cout<<"CHAT WITH HER!"<<endl;
    }
    
    
    

return 0;
}
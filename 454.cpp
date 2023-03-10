#include <bits/stdc++.h>
using namespace std;

int main()
{

    string s;

    cin >> s;


    int n = s.length();

    vector<int> v;

    for (int i = 0; i < n; i+=2)
    {
         int d = s[i]-'0';

         v.push_back(d);   
    }

    sort(v.begin(),v.end());

    for (int i = 0; i < v.size(); i++)
    {
            cout<<v[i];

            if (i<v.size()-1)
            {
                    cout<<"+";
            }
            
    }
    
    

    return 0;
}
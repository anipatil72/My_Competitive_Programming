#include <bits/stdc++.h>
using namespace std;

int main()
{

    string s;

    cin >> s;

    int n = s.length();

    int l = 0 , u = 0 ;

    for (int i = 0; i < n; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            l++;
        }
        else
        {
            u++;
        }
    }


    // cout<<"The value of l is : "<<l<<endl;
    // cout<<"The value of u is : "<<u<<endl;

    if (l < u)
    {
        for (int i = 0; i < n; i++)
        {

            if (s[i] >= 'a' && s[i] <= 'z')
            {
                s[i] = s[i] - 32;
            }
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {

            if (s[i] >= 'A' && s[i] <= 'Z')
            {
                s[i] = s[i] + 32;
            }
        }
    }

    cout<<s<<endl;

    return 0;
}
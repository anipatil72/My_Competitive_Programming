#include <bits/stdc++.h>
using namespace std;

int myAtoi(string s)
{

    int n = s.length();

    int i = 0;

    while ((i < n) && (s[i] < '0' || s[i] > '9'))
    {

        if (s[i]=='-')
        {
                if ((i<n-1)&&(s[i + 1] >= '0'&& s[i+1] <= '9'))
                {
                    break;   
                }
                
        }
        

        i++;
    }

    int j = i;

    // cout<<"The value of i is "<<i<<endl;

    if (s[j]=='-')
    {
        j++;
    }

    while ((s[j] >= '0' && s[j] <= '9'))
    {
        j++;
    }

    // cout<<"The value of j is "<<j<<endl;
    string par = s.substr(i);
    // cout<<par<<endl;

    return stoi(par) ;
}

int main()
{

    string s = "There we go -+ private -12 lkkb ";

    // cin>>s;

    cout << myAtoi(s);

    // cout<<s.substr(1,12);

    return 0;
}
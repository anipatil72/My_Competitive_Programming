#include <bits/stdc++.h>
using namespace std;

string afterDecimal(const string& s)
{
    int pos = s.find('.');

    if (pos == -1)
    {
        return "";
    }
    
        return s.substr(pos + 1);
    
}

int main()
{

    string num = "5.925";

    // cout<<afterDecimal(num);

    string s;

      getline(cin,s);

      cout<<s<<endl;

    return 0;
}
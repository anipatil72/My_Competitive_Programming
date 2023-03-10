#include <bits/stdc++.h>
using namespace std;

int main()
{

    string s, r;

    cin >> s;
    cin >> r;

    for (int i = 0; i < s.length(); i++)
    {

        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] += 32;
        }
    }

    for (int i = 0; i < r.length(); i++)
    {

        if (r[i] >= 'A' && r[i] <= 'Z')
        {
            r[i] += 32;
        }
    }

    if (s < r)
    {
        cout << "-1" << endl;
    }
    else if (r == s)
    {
        cout << "0" << endl;
    }
    else
    {
        cout << "1" << endl;
    }

    // char c = 'A';

    // c = c + 32;

    // cout<<c<<endl;

    return 0;
}
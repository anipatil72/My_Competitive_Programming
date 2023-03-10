#include <bits/stdc++.h>
using namespace std;

int main()
{

    string s;

    cin >> s;

    string a = "0000000";
    string b = "1111111";

    if ((s.find(a) != string::npos) || (s.find(b) != string::npos))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
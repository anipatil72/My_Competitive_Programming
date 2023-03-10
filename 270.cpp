#include <bits/stdc++.h>
using namespace std;

bool areRotaions(string &a, string &b)
{
    if (a.length() != b.length())
    {
        return false;
    }

    return ((a + a).find(b) != string::npos);
}

int main()
{

    string s = "ABCD";
    string t = "CDABB";

    cout << areRotaions(s, t);

    return 0;
}
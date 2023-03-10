#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

bool IsPalindrome(string s)
{

    for (int i = 0; i < s.length() / 2; i++)
    {
        if (s[i] == s[s.length() - 1 - i])
        {
            continue;
        }

        return false;
    }

    return true;
}

int PInd(string s)
{

    int i, j, k = 0, l;

    string d;

    for (i = 0; i < s.length(); i++)
    {

        d = s;

        d.erase(d.begin() + i);

        if (IsPalindrome(d))
        {
            k++;
        }
    }

    return k;
}

int main()
{

    int t, i;

    cin >> t;

    int n[t];
    string s[t];

    for (i = 0; i < t; i++)
    {

        cin >> n[i];
        cin >> s[i];
    }

    for (i = 0; i < t; i++)
    {
        int y = PInd(s[i]);

        cout << y << endl;
    }

    return 0;
}
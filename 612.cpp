#include <bits/stdc++.h>
using namespace std;

void recur(string &a, int left)
{
    a.erase(a.begin() + left, a.begin() + left + 2);
}

string makeGood(string s)
{
    int n = s.length();

    if (n == 1)
    {
        return s;
    }

    for (int j = 0; j < 100; j++)
    {
        bool flag = false;
        for (int i = 0; i < s.length() - 1; i++)
        {
            if (abs(s[i] - s[i + 1]) == 32)
            {
                recur(s, i);

                flag = true;

                break;
            }
        }

        if (flag)
        {
            continue;
        }

        break;
    }

    return s;
}

int main()
{

    string s = "leEeetcode";

    cout << makeGood(s);

    // char x = 'z';

    // char y = x - 32;

    // cout << y << endl;

    return 0;
}
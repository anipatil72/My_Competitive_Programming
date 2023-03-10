#include <bits/stdc++.h>
using namespace std;

int solve(string s)
{

    int ans;

    char c, j, k;

    cin >> s;

    stack<char> a;

    for (int i = 0; i < s.size(); i++)
    {

        if (s[i] == '(')
        {
            a.push(s[i]);

            continue;
        }

        if (a.empty())
        {
            if (s[i] == ')')
            {
                return 0;
            }
        }
        if (!a.empty())
        {
            if (s[i] == ')' && a.top() == '(')
            {
                a.pop();
                continue;
            }

            if (s[i] == ')' && a.top() != '(')
            {
                return 0;
            }
        }

    }

    if (a.empty())
    {
        return 1;
    }

    return 0;
}

int main()
{

    return 0;
}
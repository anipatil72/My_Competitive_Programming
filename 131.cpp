#include <bits/stdc++.h>
using namespace std;

string interpret(string command)
{

    int n = command.length();

    string ans = "";

    int i = 0;

    while (i < n)
    {

        //cout << "I am here!" << endl;
        char d, f;

        d = command[i];

        if (d == 'G')
        {
            ans = ans + 'G';
            i++;
            continue;
        }

        if (d == '(')
        {
            f = command[i + 1];

            if (f == ')')
            {
                ans = ans + 'o';
                i += 2;
                continue;
            }

            if (f == 'a')
            {
                ans = ans + "al";
                i += 4;
                continue;
            }
        }
    }

    return ans;
}

int main()
{

    string s = "(al)G(al)()()G";

    string s1 = interpret(s);

    cout << s1 << endl;

    return 0;
}
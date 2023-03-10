#include <bits/stdc++.h>
using namespace std;

string lexicog(string s, int n)
{
    string b = "", k = "";

    b = b + s[0];

    for (int i = 1; i < n; i++)
    {
        // int lb = b.length();

        if (b.back() >= s[i])
        {
            b = b + s[i];
            continue;
        }
        else
        {

            // int cur = b.length() - 1;

            while (b.back() < s[i])
            {

                //cout<<"I am here!"<<endl;
                char c = b.back();

                b.pop_back();

                k = k + c;
            }

            b = b + s[i];
        }
    }

    while (b.length() != 0)
    {

        char c = b.back();

        b.pop_back();
        k = k + c;
    }

    return k;
}

int main()
{

    string s = "fixed";

    string s1 = lexicog(s, s.length());

    cout << s1 << endl;

    return 0;
}
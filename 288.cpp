#include <bits/stdc++.h>
using namespace std;

int convertStringToInt(string s)
{
    int num = 0;

    // convert binary string into integer
    for (int i = 0; i < s.size(); i++)
    {
        num = num * 2 + (s[i] - '0');
    }
    return num;
}

int solve(int A, int B, int C)
{

    int h = (1 << 31);

    string s = "";

    for (int j = 0; j < 32; j++)
    {
        int last = (A & h);

        if (last != 0)
        {
            s += "1";
        }
        else
        {
            s += "0";
        }

        A = A << 1;

        // cout<<last<<endl;
    }

    swap(s[32 - B], s[32 - C]);

    return convertStringToInt(s);
}

int main()
{

    return 0;
}
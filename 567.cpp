#include <bits/stdc++.h>
using namespace std;

int addDigits(int num)
{
    if (num<=9)
    {
        return num;
    }


    int res = 0;

    string s = to_string(num);

    for (int i = 0; i < s.length(); i++)
    {
            res+=s[i] - '0';
    }


    return addDigits(res);
    
    
}

int main()
{

    return 0;
}
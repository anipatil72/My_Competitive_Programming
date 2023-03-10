#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s)
{

    int n = s.length();

    int i = 0, j = n - 1;

    while (i < j)
    {
        while (i<n&&!iswalnum(s[i]))
        {
            i++;
        }

        if (i<n&&s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] += 32;
        }

        while (j>=0&&!iswalnum(s[j]))
        {
            j--;
        }

        if ((j>=0)&&s[j] >= 'A' && s[j] <= 'Z')
        {
            s[j] += 32;
        }

        if (i >= j)
        {
            return true;
        }

        if (s[i] != s[j])
        {
            return false;
        }

        i++;
        j--;
    }

    return true;
}

int main()
{

    // char c = 'A';

    // c+=32;

    // cout<<c;

    return 0;
}
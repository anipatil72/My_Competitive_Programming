#include <bits/stdc++.h>
using namespace std;

bool isSubSeq(string s1, string s2)
{

    int n = s1.length();

    int m = s2.length();

    int i = 0, j = 0;

    while (i < n && j < m)
    {
        if (s1[i] == s2[j])
        {
            i++;
            j++;
            continue;
        }

        i++;
    }

    if (j == (m) && i < n)
    {
        return 1;
    }

    if (i == (n) && j == (m))
    {
        return 1;
    }

    return 0;
}

int main()
{

    string e = "geeksforgeeks";
    string f = "grges";

    cout<<isSubSeq(e,f)<<endl;

    return 0;
}
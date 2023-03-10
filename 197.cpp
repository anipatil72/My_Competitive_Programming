#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string s1, string s2)
{

    if (s1.length() != s2.length())
    {
        return 0;
    }

    int n = s1.length();

    const int CHAR = 256;

    int count[CHAR] = {0};

    for (int i = 0; i < n; i++)
    {
        count[s1[i]]++;
        count[s2[i]]--;
    }

    for (int i = 0; i < CHAR; i++)
    {
        if (count[i] != 0)
        {
            return 0;
        }
    }

    return 1;
}

int main()
{

    string s1 = "listen", s2 = "silnet";

    cout << isAnagram(s1,s2);



    return 0;
}
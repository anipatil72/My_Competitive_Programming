#include <bits/stdc++.h>
using namespace std;

bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2)
{

    string p = "";
    string q = "";

    for (int i = 0; i < word1.size(); i++)
    {
        p += word1[i];
    }

    for (int i = 0; i < word2.size(); i++)
    {
        q += word2[i];
    }

    return p == q;
}

int main()
{

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int strString(string haystack, string needle)
{

    int n = haystack.length();
    int m = needle.length();

    if (m == 0)
    {
        return 0;
    }

    if (m > n)
    {
        return -1;
    }

    return haystack.find(needle);
}

int main()
{

    string text = "This is all very standard, nothing out of the ordinary !";

    string pattern = "hello";

    cout<<strString(text,pattern);

    return 0;
}
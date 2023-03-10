#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s)
{

    int n = s.length();

    string ans = "";

    int i = 0;

    while (i < n && s[i] == ' ')
    {
        i++;
    }

    int j = n - 1;

    while (j >= 0 && s[j] == ' ')
    {
        j--;
    }

    while (j >= i)
    {
        string word = "";

        while (j >= i && s[j] != ' ')
        {
            word += s[j];

            j--;
        }

        reverse(word.begin(), word.end());

        ans += word;

        ans += ' ';

        word = "";

        while (j >= i && s[j] == ' ')
        {
            j--;
        }
    }

    ans.pop_back();

    return ans;
}

int main()
{

    return 0;
}
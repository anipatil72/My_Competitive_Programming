#include <bits/stdc++.h>
using namespace std;

bool wordPattern(string pattern, string s)
{

    int n = pattern.length() + 1;

    unordered_map<char, string> m;
    unordered_map<string, char> p;

    pattern += ' ';

    int i = 0, j = 0;

    string word = "";

    while (i < n)
    {
        if (pattern[i] == ' ')
        {
            if (m.count(s[j]) > 0 || p.count(word) > 0)
            {
                if (m[s[j]] != word || p[word] != s[j])
                {
                    
                    return false;
                }
            }
            else if (j < s.length())
            {
                m[s[j]] = word;
                p[word] = s[j];
            }
            else if (j >= s.length())
            {
                return false;
            }

            // cout<<word<<endl;

            word = "";

            j++;
        }
        else
        {
            word += pattern[i];
        }

        i++;
    }

    return true;
}

int main()
{
    string a = "abba", b = "dog cat cat fish";

    cout << wordPattern(b, a);

    return 0;
}
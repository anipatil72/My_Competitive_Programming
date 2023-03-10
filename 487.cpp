#include <bits/stdc++.h>
using namespace std;

bool canConstruct(string ransomNote, string magazine)
{

    int n = magazine.length();

    int m = ransomNote.length();

    vector<int> mag(26, 0);

    vector<int> ran(26, 0);

    for (int i = 0; i < n; i++)
    {
        mag[magazine[i] - 'a']++;
    }

    for (int i = 0; i < m; i++)
    {
        ran[ransomNote[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++)
    {
        if (mag[i] < ran[i])
        {
            return false;
        }
    }

    return true;
}

int main()
{

    return 0;
}
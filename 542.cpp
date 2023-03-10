#include <bits/stdc++.h>
using namespace std;

bool checkIfPangram(string sentence)
{
    int n = sentence.length();

    vector<int> v(26, 0);

    for (int i = 0; i < n; i++)
    {
        v[sentence[i] - 'a'] = 1;
    }

    for (int i = 0; i < 26; i++)
    {
        if (v[i] == 0)
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
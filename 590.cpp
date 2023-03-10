#include <bits/stdc++.h>
using namespace std;

string reverseVowels(string s)
{

    int n = s.length();

    string ans = s;

    vector<int> pos;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
        {
            pos.push_back(i);
        }
    }

    int x = pos.size();

    for (int i = 0; i < x / 2; i++)
    {
        swap(ans[pos[i]], ans[pos[x - 1 - i]]);
    }

    return ans;
}

int main()
{

    cout<<reverseVowels("hello")<<endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

string getHint(string secret, string guess)
{
    int n = secret.length();

    vector<int> f(10, 0);

    for (int i = 0; i < n; i++)
    {
        f[secret[i] - '0']++;
    }

    int bull = 0, cow = 0;

    for (int i = 0; i < n; i++)
    {
        if (secret[i] == guess[i])
        {
            bull++;

            f[secret[i] - '0']--;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if ((guess[i] != secret[i]) && (f[guess[i] - '0'] > 0))
        {
            cow++;
            f[guess[i] - '0']--;
        }
    }

    string ans = "";

    ans += to_string(bull);

    ans += "A";
    ans += to_string(cow);
    ans += "B";

    return ans;
}

int main()
{

    return 0;
}
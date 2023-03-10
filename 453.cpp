#include <bits/stdc++.h>
using namespace std;

int main()
{

    string a, b, c;

    cin >> a >> b >> c;

    vector<int> v(26, 0);

    for (int i = 0; i < a.length(); i++)
    {
        v[a[i] - 'A']++;
    }

    for (int i = 0; i < b.length(); i++)
    {
        v[b[i] - 'A']++;
    }

    for (int i = 0; i < c.length(); i++)
    {
        v[c[i] - 'A']--;
    }

    bool flag = 0;

    for (int i = 0; i < 26; i++)
    {
        if (v[i] != 0)
        {
            flag = true;

            break;
        }
    }

    if (flag)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
    }

    return 0;
}
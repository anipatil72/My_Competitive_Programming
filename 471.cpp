#include <bits/stdc++.h>
using namespace std;

void solve(int n, string &s)
{
    vector<int> fir(n, 0);
    vector<int> sec(n, 0);

    for (int i = 0; i < n; i++)
    {
        // cin >> fir[i];

        fir[i] = s[i] - '0';
    }

    for (int i = 0; i < n; i++)
    {
        // cin >> sec[i];

        sec[i] = s[n + i] - '0';
    }

    sort(fir.begin(), fir.end());
    sort(sec.begin(), sec.end());

    // for (int i = 0; i < n; i++)
    // {
    //     cout << fir[i] << " ";
    // }

    // cout << endl;

    // for (int i = 0; i < n; i++)
    // {
    //     cout << sec[i] << " ";
    // }

    // cout << endl;

    bool flag = true;

    for (int i = 0; i < n; i++)
    {
        if (sec[i] >= fir[i])
        {
            flag = false;
            break;
        }
    }

    if (flag)
    {
        cout << "YES" << endl;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (sec[i] <= fir[i])
        {
            flag = true;
            break;
        }
    }

    if (!flag)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}

int main()
{

    int n;

    cin >> n;

    string s;

    cin >> s;

    solve(n, s);

    return 0;
}
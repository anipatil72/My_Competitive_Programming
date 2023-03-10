#include <bits/stdc++.h>
using namespace std;

void solve()
{

    long long int n, d;
    bool ans;
    unordered_map<int, int> m;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> d;

        int l = d % 10;

        m[l]++;
    }

    // cout<<m[12]<<"is the value for 12 in map"<<endl;

    if (m[1] >= 3)
    {
        cout << "YES" << endl;
        return;
    }
    if (m[0] >= 2 && m[3] > 0)
    {
        cout << "YES" << endl;
        return;
    }
    if (m[1] > 0 && m[2] > 0 && m[0] > 0)
    {
        cout << "YES" << endl;
        return;
    }
    if (m[7] > 0 && m[6] > 0 && m[0] > 0)
    {
        cout << "YES" << endl;
        return;
    }

    if (m[3] >= 2 && m[7] > 0)
    {
        cout << "YES" << endl;
        return;
    }

    if (m[4] > 0 && m[6] > 0 && m[3] > 0)
    {
        cout << "YES" << endl;
        return;
    }
    if (m[4] > 0 && m[7] > 0 && m[2] > 0)
    {
        cout << "YES" << endl;
        return;
    }
    if (m[7] > 0 && m[5] > 0 && m[1] > 0)
    {
        cout << "YES" << endl;
        return;
    }
    if (m[1] > 0 && m[6] >= 2)
    {
        cout << "YES" << endl;
        return;
    }
    if (m[2] > 0 && m[6] > 0 && m[5] > 0)
    {
        cout << "YES" << endl;
        return;
    }
    if (m[8] > 0 && m[5] > 0 && m[0] > 0)
    {
        cout << "YES" << endl;
        return;
    }
    if (m[5] > 0 && m[4] >= 2)
    {
        cout << "YES" << endl;
        return;
    }
    if (m[3] > 0 && m[5] >= 2)
    {
        cout << "YES" << endl;
        return;
    }

    if (m[8] > 0 && m[4] > 0 && m[1] > 0)
    {
        cout << "YES" << endl;
        return;
    }

    if (m[8] > 0 && m[3] > 0 && m[2] > 0)
    {
        cout << "YES" << endl;
        return;
    }

    if (m[9] > 0 && m[4] > 0 && m[0] > 0)
    {
        cout << "YES" << endl;
        return;
    }

    if (m[9] > 0 && m[3] > 0 && m[1] > 0)
    {
        cout << "YES" << endl;
        return;
    }

    if (m[9] > 0 && m[2] >= 2)
    {
        cout << "YES" << endl;
        return;
    }

    if (m[8] >= 2 && m[7] > 0)
    {
        cout << "YES" << endl;
        return;
    }

    if (m[9] > 0 && m[6] > 0 && m[8] > 0)
    {
        cout << "YES" << endl;
        return;
    }

    if (m[9] >= 2 && m[5] > 0)
    {
        cout << "YES" << endl;
        return;
    }

    if (m[9] > 0 && m[7] > 0 && m[6] > 0)
    {
        cout << "YES" << endl;
        return;
    }

    cout << "NO" << endl;
}

int main()
{

    int t;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        solve();
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n, -1);
    vector<int> freq(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        freq[a[i]]++;
    }

    // This will store numbers that were not wished by anyone.
    set<int> not_wished;
    for (int i = 1; i <= n; i++)
    {
        if (freq[i] == 0)
            not_wished.insert(i);
    }

    for (int i = 0; i < n; i++)
    {
        if (a[i] != i + 1 && b[a[i] - 1] == -1)
        {
            b[i] = a[i];
            not_wished.erase(a[i]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (b[i] == -1)
        {
            if (not_wished.size() && *not_wished.begin() != i + 1)
            {
                b[i] = *not_wished.begin();
                not_wished.erase(b[i]);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (b[i] == -1)
        {
            for (int j = 1; j <= n; j++)
            {
                if (b[j - 1] == -1 && j != i + 1)
                {
                    b[i] = j;
                    break;
                }
            }
        }
    }

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == b[i])
            count++;
    }

    cout << count << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << b[i] << " ";
    }
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

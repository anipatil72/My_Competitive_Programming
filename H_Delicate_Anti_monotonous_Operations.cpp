#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n, w;
    cin >> n >> w;
    vector<ll> a(n);
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }

    queue<int> q;
    vector<bool> in_queue(n - 1, false);

    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] == a[i + 1] && a[i] < w)
        {
            q.push(i);
            in_queue[i] = true;
        }
    }

    int ops = 0;

    while (!q.empty())
    {
        int i = q.front();
        q.pop();
        in_queue[i] = false;

        if (a[i] != a[i + 1] || a[i] >= w)
            continue;

        ll old_val = a[i];
        sum += (w - 1 + w) - (old_val * 2);
        ops++;

        a[i] = w - 1;
        a[i + 1] = w;

        if (i > 0 && a[i - 1] == a[i] && a[i] < w && !in_queue[i - 1])
        {
            q.push(i - 1);
            in_queue[i - 1] = true;
        }
        if (i + 2 < n && a[i + 1] == a[i + 2] && a[i + 1] < w && !in_queue[i + 1])
        {
            q.push(i + 1);
            in_queue[i + 1] = true;
        }
    }

    cout << sum << ' ' << ops << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
#include <bits/stdc++.h>
#define nl "\n"

#define ll long long
#define loop n % 3 ==
#define loop1 n % 3 == 1
#define loop2

#define loop3

#define loop4

#define pb push_back
#define all(v) v.begin(), v.end()
#define vil vectorsll<ll>

#define inf 1999999996000000010
//___________________________CODE_BY_ANIRUDDHA_PATIL_____________

using namespace std;

void solve()
{
    int n;
    cin >> n;
    int b[n];
    for (int i = 1; i <= n; i++)
    {
        b[i - 1] = i;
    }
    if (n == 1)
    {
        int a;
        cin >> a;
        cout << "-1" << endl;
        return;
    }
    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(b, b + n);
    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i])
        {

            continue;
        }

        if (i == n - 1)
        {

            swap(b[n - 1], b[n - 2]);
        }

        else
        {
            swap(b[i], b[i + 1]);
        }
        for (auto x : b)
        {
            cout << x << " ";
        }
            cout << endl;
    }
}

int main()
{
    ll k;
    cin >> k;
    ll temp = k;
    while (k--)
    {
        // cout << "Case #" << temp - k <<
        solve();
    }
        return (0);
}

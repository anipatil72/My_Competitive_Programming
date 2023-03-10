#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{

    ll n, m;

    cin>>n>>m;

    ll cur = 1;

    ll ans = 0;

    for (int i = 0; i < m; i++)
    {
        ll d;

        cin >> d;

        if (d >= cur)
        {
            ans += d - cur;

            cur = d;
        }
        else
        {
            ans += n- cur + d;

            cur = d;
        }
    }

    cout << ans << endl;

    return 0;
}
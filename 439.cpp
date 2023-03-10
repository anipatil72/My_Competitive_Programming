#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;

    cin>>n;

    long double ans = 0;

    // cout<<ans;

    for (int i = 0; i < n; i++)
    {

        int d;

        cin >> d;

        ans += ((long double)d) / 100;
    }

    ans = ans / n;

    ans*=100;

    cout << ans << endl;

    return 0;
}
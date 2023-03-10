#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define I_am_speed()                  \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define vec vector<ll>
#define loop(x, start, end) for (int x = start; x < end; ++x)

void print(vector<ll> &v)
{
    int n = v.size();
    for (int i = 0; i < v.size() - 1; i++)
    {
        cout << v[i] << " ";
    }
    cout << v[n - 1] << endl;
    return;
}
void print_2d(vector<vector<ll>> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    return;
}
void solve()
{
    int n, k;
    cin >> n >> k;
    vec s(n);
    loop(i, 0, n) cin >> s[i];
    vec a(n, 0);
    if (n == k)
    {

        a[0] = s[0];
        for (int i = 1; i < n; i++)
        {
            a[i] = s[i] - s[i - 1];
        }
        for (int i = 0; i < n - 1; i++)
        {
            if (a[i + 1] < a[i])
            {
                cout << "NO1"
                     << "\n";
                return;
            }
        }
        cout << "Yes1"
             << "\n";
    }
    else
    {
        int min1 = s[1] - s[0];
        for (int i = 2; i < k; i++)
        {
            if (min1 > s[i] - s[i - 1])
            {
                cout << "No2" << endl;
                return;
            }
        }
        for (int i = 1; i < k; i++)
        {

            a[i + n - k] = s[i] - s[i - 1];
        }
        if (k * a[1 + n - k] < s[0])
        {
            cout << "no3"
                 << "\n";
            return;
        }
        cout << "yes2" << endl;
    }
    return;
}

int main()
{
    I_am_speed();
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
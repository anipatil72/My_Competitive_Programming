#include <bits/stdc++.h>
using namespace std;

int main()
{

    long long int t, d, g, n, m, q, x, y, sum = 0;

    vector<long long int> v;
    vector<long long int> p;

    cin >> n >> q;

    for (int i = 0; i < n; i++)
    {
        cin >> d;
        v.push_back(d);
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++)
    {
        sum = sum + v[i];
        p.push_back(sum);
    }

    // for (int i = 0; i < n; i++)
    // {
    //         cout<<p[i]<<" ";
    // }

    for (int i = 0; i < q; i++)
    {
        cin >> x >> y;

        if ((n - x - 1) >= 0)
        {
            cout << p[(n - x - 1 + y)] - p[(n - x - 1)] << endl;
        }

        if ((n - x) == 0)
        {
            cout << p[y - 1] << endl;
        }
    }

    return 0;
}
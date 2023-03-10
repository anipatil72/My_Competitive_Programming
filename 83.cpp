#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, f = 0, g, h, d, sum = 0;

    unordered_map<int, int> m;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> d;

        // cout<<d<<endl;
        sum = sum + d;
        // cout<<sum<<endl;

        if (m.count(sum) > 0)
        {

            f = max(f, i - m[sum]);
            continue;
        }
        if (m.count(0) <= 0 && sum == 0)
        {
            f = i + 1;
            continue;
        }

        m[sum] = i;
    }

    cout << f << endl;

    return 0;
}
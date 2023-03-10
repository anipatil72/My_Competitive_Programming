#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;

    cin >> n;

    vector<int> v(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int can1 = 0, can2 = 1;

    int m = INT_MAX;

    for (int i = 1; i < n; i++)
    {
        if (abs(v[i] - v[i - 1]) < m)
        {
            m = abs(v[i] - v[i - 1]);

            can1 = i - 1;
            can2 = i;
        }
    }

    if (abs(v[n - 1] - v[0]) < m)
    {
        can1 = 0;
        can2 = n - 1;
    }

    cout << can1 + 1 << " " << can2  + 1<< "\n";

    return 0;
}
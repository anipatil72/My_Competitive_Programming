#include <bits/stdc++.h>
using namespace std;

int main()
{

    int l = 0, r = 0;

    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int c, d;

        cin >> c >> d;

        if (c)
        {
            l++;
        }

        if (d)
        {
            r++;
        }
    }

    cout << min(n - l, l) + min(n - r, r) << endl;

    return 0;
}
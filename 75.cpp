#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, x, y;

    cin >> t;

    for (int q = 0; q < t; q++)
    {
        cin >> n;

        int  p = 1 ;

        int a[n], b[n];

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }

        for (int i = 0; i < n; i++)
        {
            if (a[i] != 0)
            {
                x = a[i] - b[i];
                break;
            }
        }

        for (int i = 0; i < n; i++)
        {

            if (x < 0)
            {
                p = 0;
                break;
            }

            a[i] = a[i] - x;
            if (a[i] < 0)
            {
                a[i] = 0;
            }

            // cout<<a[i]<<" "<<endl;
            // cout<<x<<endl;

            if (a[i] == b[i])
            {
                 p = 1 ;
            }
            if (a[i] != b[i])
            {
                p = 0;
                break;
            }
        }

        if (p == 0)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }

    return 0;
}
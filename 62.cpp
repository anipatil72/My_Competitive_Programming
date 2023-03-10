#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;

    cin >> t;
    int b[t];

    for (int i = 0; i < t; i++)
    {
        int n, even = 0, odd = 0;
        cin >> n;

        for (int j = 0; j < n; j++)
        {
            int a;
            cin >> a;

            if (a % 2 == 0)
            {
                even++;
            }

            if (a % 2 != 0)
            {
                odd++;
            }
        }

        b[i] = (even > odd ? odd : even);
    }

    for (int i = 0; i < t; i++)
    {
        cout << b[i] << endl;
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[3][3] = {0};

    int d;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> d;

            a[i][j] += d;

            if (i > 0)
            {
                a[i - 1][j] += d;
            }

            if (j > 0)
            {
                a[i][j - 1] += d;
            }

            if (i + 1 < 3)
            {
                a[i + 1][j] += d;
            }

            if (j + 1 < 3)
            {
                a[i][j + 1] += d;
            }
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (a[i][j] % 2 == 0)
            {
                cout << "1";
            }
            else
            {
                cout << "0";
            }
        }

        cout << "\n";
    }

    return 0;
}
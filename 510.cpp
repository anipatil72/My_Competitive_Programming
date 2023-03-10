#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;

    cin >> n;

    int l = 1, m = n * n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j % 2 == 0)
            {
                cout << l << " ";

                l++;
            }
            else
            {
                cout << m << " ";

                m--;
            }
        }

        cout << endl;
    }

    return 0;
}
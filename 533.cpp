#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n, m;

    vector<int> a, b;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int d;

        cin >> d;

        a.push_back(d);
    }

    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int d;

        cin >> d;

        b.push_back(d);
    }

    int M = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (b[j] % a[i] == 0)
            {
                M = max(M, b[j] / a[i]);
            }
        }
    }

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (b[j] % a[i] == 0)
            {
                // M = max(M, b[j]/a[i]);

                if (b[j] / a[i] == M)
                {
                    count++;
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;

    cin >> n >> m;

    vector<int> high(m, INT_MIN);

    vector<string> grades(n);

    string s;

    for (int i = 0; i < n; i++)
    {
        cin >> grades[i];

        for (int j = 0; j < m; j++)
        {
            high[j] = max(high[j], grades[i][j] - '0');
        }
    }

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if ((grades[i][j] - '0') == high[j])
            {
                count++;
                break;
            }
        }
    }

    cout << count << endl;
}

int main()
{

    solve();

    return 0;
}
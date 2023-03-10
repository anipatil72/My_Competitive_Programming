#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;

    cin >> n;

    unordered_map<string, int> m;

    int g = 0;
    string win, t;

    for (int i = 0; i < n; i++)
    {
        cin >> t;

        m[t]++;

        if (m[t] > g)
        {
            win = t;
            g = m[t];
        }
    }

    cout << win << endl;

    return 0;
}
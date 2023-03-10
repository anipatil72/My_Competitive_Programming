#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n, d, f, g;
    cin >> n;

    unordered_map<int, int> m;
    vector<int> v;

    for (int i = 0; i < n; i++)
    {
        cin >> d;
        if (m.count(d) > 0)
        {
            m[d]++;
            continue;
        }
        if (m.count(d) <= 0)
        {
            v.push_back(d);
            m[d]++;
        }
    }

    int sum = 0;

    for (int i = 0; i < v.size(); i++)
    {
        if (m.count(-1 * v[i]) > 0&&v[i]!=0)
        {
            sum = sum + m[v[i]] * m[-1 * v[i]];
        }
    }

    sum = sum / 2;

    cout << sum << endl;

    return 0;
}
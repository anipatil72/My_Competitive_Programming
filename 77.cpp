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

    g = 0;

    for (int i = 0; i < v.size(); i++)
    {

        // cout<<v[i]<<" ";

        if (m[v[i]] > g)
        {
            g = m[v[i]];
            f = i;
        }
    }

    cout << "The maximum frequency is : " << g << " corresponding to " << v[f] << endl;
            // cout<<m[2]<<endl;

    return 0;
}
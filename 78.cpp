#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n, m, d, f, g, t;
    unordered_map<int, int> m1;
    unordered_map<int, int> m2;

    vector<int> v1;
    vector<int> v2;

    cin >> t;

    for (int j = 0; j < t; j++)
    {

        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cin >> d;

            if (m1.count(d) > 0)
            {
                m1[d]++;
                continue;
            }
            if (m1.count(d) <= 0)
            {
                v1.push_back(d);
                m1[d]++;
            }
        }

        cin >> m;

        for (int i = 0; i < m; i++)
        {
            cin >> d;

            if (m2.count(d) > 0)
            {
                m2[d]++;
                continue;
            }
            if (m2.count(d) <= 0)
            {
                v2.push_back(d);
                m2[d]++;
            }
        }
        // cout<<endl;

        for (int i = 0; i < v1.size(); i++)
        {
            if (m2.count(v1[i]) > 0)
            {
                cout << v1[i] << " ";
            }
        }

        cout << endl;
    }

    return 0;
}
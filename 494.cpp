#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;

    cin >> n;

    map<int, pair<int, int>> m;

    for (int i = 0; i < n; i++)
    {
        int d;

        cin >> d;

        m[d].first++;

        m[d].second = i;
    }

    auto i = m.begin();

    if ((i->second).first >= 2)
    {
        cout << "Still Rozdil" << endl;
    }
    else
    {
        cout << (i->second).second + 1 << endl;
    }

    return 0;
}
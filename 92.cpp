#include <bits/stdc++.h>
using namespace std;

int main()
{

    priority_queue<int, vector<int>, greater<int>> p;

    int n, d, f, g;

    int t;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> n;

        for (int j = 0; j < n; j++)
        {
            cin >> d;
            p.push(d);
        }
    }

    while (!p.empty())
    {
        cout << p.top() << " ";
        p.pop();
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{

    int a[] = {2, 15, 7, 29, 78, 45, 9};

    stack<int> s;
    vector<int> v;

    int n = sizeof(a) / sizeof(int);

    s.push(a[n - 1]);
    v.push_back(-1);

    for (int i = n - 2; i >= 0; i--)
    {
        while (!s.empty() && a[i] > s.top())
        {
            s.pop();
        }

        int ans = (s.empty() ? -1 : s.top());
        v.push_back(ans);

        // cout<<ans<<" ";
        s.push(a[i]);
    }

    for (int i = v.size() - 1; i >= 0; i--)
    {

        cout << v[i] << " ";
    }

    return 0;
}
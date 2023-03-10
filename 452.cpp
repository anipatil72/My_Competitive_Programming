#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;

    cin >> n;

    int cur = 0;

    int m = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        int a, b;

        cin >> a >> b;

        cur += b;

        cur -= a;

        m = max(m, cur);
    }


    cout<<m<<endl;

    return 0;
}
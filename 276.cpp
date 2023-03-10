#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n, m, x, t, d;

    cin >> n >> m >> x >> t >> d;

    int age ;

    if (m > x)
    {
        age = t;
    }

    if (m <= x)
    {
        age = t - (x-m)*d;
    }

    cout << age << endl;

    return 0;
}
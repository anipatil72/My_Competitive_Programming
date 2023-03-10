#include <bits/stdc++.h>
using namespace std;

int GCD(int a, int b)
{
    // Everything divides 0
    if (a == 0)
       return b;
    if (b == 0)
       return a;
  
    // base case
    if (a == b)
        return a;
  
    // a is greater
    if (a > b)
        return GCD(a-b, b);
    return GCD(a, b-a);
}

long long LCM(int a, int b)
{
    return (a / GCD(a, b)) * b;
}

int main()
{

    int t;

    // cout << LCM(1, 5) << endl;
    // cout << GCD(1, 5) << endl;

    cin >> t;

    for (int i = 0; i < t; i++)
    {

        long long int n, x, y, m = 0, f;

        cin >> n;

        for (int i = 1; i <= n / 2; i++)
        {
            x = LCM(i, n - i);
            y = GCD(i, n - i);

            f = x - y;

            m = max(m, f);
        }

        cout << m << endl;
    }

    return 0;
}
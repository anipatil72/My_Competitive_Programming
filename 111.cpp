#include <bits/stdc++.h>
using namespace std;

int GCD(int a, int b)
{
    if (b == 0)
    {
        return a;
    }

    return GCD(b, a % b);
}

int LCM(int a, int b)
{
    return (a * b) / GCD(a, b);
}

int findF(int n)
{
    int m = INT_MAX;
    for (int i = 1; i*i <= n; i++)
    {
        m = min(m, GCD(i, n - i) + LCM(i, n - i));
    }
    return m;
}

int main()
{

    int  t;

    cin >> t;

    for (int i = 0; i < t; i++)
    {

        int N ;

        cin >> N;
        int count = 0;
        int f = findF(N);

        for (int j = 1; j<= N/2; j++)
        {
            int x = GCD(j,N-j);

            int temp = x + j*(N-j)/x;

            if (temp == f && j + j != N)
            {
                count = count + 2;
            }

            if (temp == f && j + j == N)
            {
                count++;
            }
        }

        cout << count << endl;
    }

    return 0;
}
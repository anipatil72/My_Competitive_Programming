#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;

    cin >> n;

    int sum = 0, even = 0, odd = 0;

    for (int i = 0; i < n; i++)
    {
        int d;

        cin >> d;

        if (d % 2 == 0)
        {
            even++;
        }
        else
        {
            odd++;
        }

        sum += d;
    }

    if (sum % 2 == 0)
    {
        cout << even << endl;
    }
    else
    {
        cout << odd << endl;
    }

    return 0;
}
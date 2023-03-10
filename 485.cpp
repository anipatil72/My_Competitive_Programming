#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;

    cin >> n;

    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        int d;

        cin >> d;

        sum += d;
    }

    int count = 0;

    for (int i = 1; i <= 5; i++)
    {
        if ((sum + i) %(n+1) != 1)
        {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}
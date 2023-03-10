#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;

    cin >> n;

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        int sum = 0;

        int a, b, c;

        cin >> a >> b >> c;

        sum = a + b + c;

        if (sum >= 2)
        {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}
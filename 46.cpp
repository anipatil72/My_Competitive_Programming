#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;

    cin >> n;

    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int best = 0, sum = 0;
    for (int k = 0; k < n; k++)
    {
        sum = max(a[k], sum + a[k]);
        best = max(best, sum);
    }
    cout << "The maximum sub array sum is " << best << "\n";

    return 0;
}
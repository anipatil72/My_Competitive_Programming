#include <bits/stdc++.h>
using namespace std;

int main()
{
    int l, r, sum = 0;

    cout << "Enter the left Pointer!" << endl;
    cin >> l;

    cout << "Enter the right Pointer!" << endl;
    cin >> r;

    if (l % 3 == 0)
    {
        sum = sum + 3;
        l++;
    }

    if (l % 3 == 2)
    {
        sum = sum + 2;
        l = l + 2;
    }

    if (r % 3 == 2)
    {
        sum = sum - 3;
        r++;
    }

    if (r % 3 == 1)
    {
        sum = sum - 5;
        r = r + 2;
    }

    if ((r - l + 1) % 3 == 0)
    {
        cout << "I am there at Google!" << endl;
    }

    sum = sum + (r - l + 1) * 2;

    cout << sum << endl;

    return 0;
}
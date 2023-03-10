#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t, r, d;
    cin >> t;

    for (int i = 0; i < t; i++)
    {

        cin >> r;

        if (r <= 1399)
        {
            cout << "Division 4" << endl;
        }
        if (1400 <= r && r <= 1599)
        {
            cout << "Division 3" << endl;
        }
        if (1600 <= r && r <= 1899)
        {
            cout << "Division 2" << endl;
        }
        if (r >= 1900)
        {
            cout << "Division 1" << endl;
        }
    }

    return 0;
}
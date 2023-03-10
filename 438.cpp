#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;

    int mIndex = 0, MIndex = 0;

    int m = INT_MAX;

    int M = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        int d;

        cin >> d;

        if (d > M)
        {
            M = d;

            MIndex = i;
        }

        if (d <= m)
        {
            m = d;
            mIndex = i;
        }
    }

    // cout<<"Teh minimum index is at : "<<mIndex<<endl;
    // cout<<"Teh maximum index is at : "<<MIndex<<endl;

    if (MIndex > mIndex)
    {
        cout << MIndex + n - 1 - mIndex - 1 << endl;
    }
    else
    {
        cout << MIndex + n - 1 - mIndex << endl;
    }

    return 0;
}
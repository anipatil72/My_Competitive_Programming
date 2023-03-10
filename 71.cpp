#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
    

        long long int n, x, y;

        cin >> n >> x;


        if ((n - x) % 2 != 0 && x % 2 == 0)
        {
            cout << "NO" << endl;
        }
         if((n - x) % 2 != 0 && x % 2 != 0&&((n > x)))
        {
            cout << "YES" << endl;
        }
         if((n - x) % 2 == 0 && x % 2 == 0&&((n > x)))
        {
            cout << "YES" << endl;
        }
         if((n - x) % 2 == 0 && x % 2 != 0&&((n > x)))
        {
            cout << "YES" << endl;
        }
    }

    return 0;
}
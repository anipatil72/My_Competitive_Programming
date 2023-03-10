#include <bits/stdc++.h>
using namespace std;

long long int BitWiseOR(long long int x)
{

    long long int ans;
    for (int i = 1; 0 < 1; i++)
    {
        if (i & x > 0 && i^x >0)
        {
            ans = i;
            break;
        }
    }

    return ans;
}


int main()
{

    long long int t, d;

    cin >> t;

    int b[t];

    for (int i = 0; i < t; i++)
    {

        cin >> d;

        b[i] = BitWiseOR(d);

        
    }

    for (int i = 0; i < t; i++)
    {
        cout << b[i] << endl;
    }

    return 0;
}
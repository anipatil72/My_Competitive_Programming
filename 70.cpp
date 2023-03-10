#include <bits/stdc++.h>
using namespace std;

int main()
{

    long long int t, n, k, v;

    cin >> t;

    

    for (int i = 0; i < t; i++)
    {
        cin >> n >> k >> v;

        long long int sum = 0, d;

        for (int j = 0; j < n; j++)
        {
            cin >> d;
            sum += d;
        }

        

        if (sum < (n + k) * v && ((n + k) * v - sum) % k == 0)
        {
            
            cout << ((n + k) * v - sum) / k << endl;
        }
        else
        {
            cout<<"-1"<<endl;
        }
        
    }
    

    return 0;
}
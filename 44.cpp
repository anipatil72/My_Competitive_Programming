#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main()
{

    int t, i, j, p, q, r;
    cin >> t;

    int n[t];
    int m[t];
    int ans[t];
       
        vector<int> a;
        vector<int> b;

    for (i = 0; i < t; i++)
    {
        cin >> n[i];

        for (j = 0; j < n[i]; j++)
        {

            cin >> p;

            a.push_back(p);
        }

        cin >> m[i];

        for (j = 0; j < m[i]; j++)
        {
            

            cin >> p;

            b.push_back(p);
        }

        r = accumulate(b.begin(), b.end(), 0);
        //cout << p << endl;
        q = a.size();

        int y  = r % n[i] + 1;

        ans[i] = a[y];
    }

    // for (int i = 0; i < t; i++)
    // {

    //     for ( j = 0; j < n[i]; j++)
    //     {
    //         cout << a[j] <<" ";
                
    //     }

    //     cout<<endl;
        
    // }

    for ( i = 0; i < t; i++)
    {
            cout<<ans[i]<<endl;
    }
    

    return 0;
}
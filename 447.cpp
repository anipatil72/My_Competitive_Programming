#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;

    cin >> n;

    if (n == 1)
    {

        cout<<"0"<<endl;

        return 0;
    }

    int c ;

    cin>>c;


    int m = c;
    int M = c;

    int ans = 0;

    for (int i = 1; i < n; i++)
    {

        int d;

        cin >> d;

        if (d < m)
        {
            ans++;

            m = d;
        }
        else if (d > M)
        {
            ans++;

            M = d;


        }
    }

    cout << ans << endl;

    return 0;
}
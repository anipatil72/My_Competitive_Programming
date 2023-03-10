#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string temp;

    cin >> temp;

    int n = temp.length();

    
    

    if (n <= 10)
    {
        cout << temp << endl;
        return;
    }

    else
    {
        cout << temp[0] << n - 2 << temp[n - 1] << endl;
    }
}

int main()
{

    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        solve();
    }

    return 0;
}
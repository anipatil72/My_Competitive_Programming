#include <bits/stdc++.h>
using namespace std;

void isKthSet(int n, int k)
{

    int a = n >> k - 1;

    // int b = n>>k;

    // b<<1;

    // cout<<a<<endl;
    // cout<<b<<endl;

    if (a & 1 == 1)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}

int main()
{

    isKthSet(2, 1);

    // cout << (2 << 1) << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{

    // 1
    // 1000000000 999999999 999999999 999999998

    int a = 1000000000;

    int b = 999999999;

    int c = b;

    int d = c - 1;

    long double e = a;

    e/=b;

    long double f = c;

    f/=d;

    // if (e == f)
    // {

    //     // cout << "Ans is : ";
    //     cout << "0" << endl;
    //     // return;
    // }

    cout<<e<<"\n";
    cout<<f<<"\n";

    // cout<<(a*d)%(b*c)<<endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;






void solve(vector<int> &A)
{

    unsigned int h = (1<<31);

    int n = A.size();

    int a = 0, b = 0, x = 0;

    for (int i = 0; i < n; i++)
    {
        x = x ^ A[i];
    }

    int s = (x & (~(x - 1)));

    for (int i = 0; i < n; i++)
    {
        if ((A[i] & s) != 0)
        {
            a = a ^ A[i];
        }
        else
        {
            b = b ^ A[i];
        }
    }

    cout << a<< " " << b<< endl;
}

int main()
{


    vector<int> a = {1,1,5,6,3,9,6,3};

    solve(a);


    // cout<<((1<<31) - 900) <<endl;

    return 0;
}
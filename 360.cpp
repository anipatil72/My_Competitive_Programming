#include <bits/stdc++.h>
using namespace std;

int MincoinChange(int n, vector<int> &v)
{
    if (n == 0)
    {
        return 0;
    }

    if (n < 0)
    {
        return -1;
    }
    int r = INT_MAX ;

    for (int i = 0; i < v.size(); i++)
    {

        int f = MincoinChange(n - v[i], v);

        if (f==-1)
        {
                continue;
        }
        

        r = min(r, f);
    }

    if (r == INT_MAX )
    {
        return -1;
    }

    return r + 1;
}

int main()
{

    int sum = 2;
    vector<int> coins = {5, 10, 25};

    cout<<MincoinChange(sum,coins);

    return 0;
}
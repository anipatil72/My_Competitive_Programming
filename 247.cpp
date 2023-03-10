#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A, int B)
{

    auto it = lower_bound(A.begin(), A.end(), B);

    while (it != A.end())
    {
        if (*it !=B)
        {
            break;
        }

        it++;
    }

    int d = distance(A.begin(), it);

    return d;
}

int main()
{

    vector<int> v = {};
    int b = 6 ;

    cout<<solve(v,b);

    return 0;
}
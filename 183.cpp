#include <bits/stdc++.h>
using namespace std;

int solve(int n, int B, int C, int D, int E)
{
    int ans = INT_MAX;
    for (int i = 0; i <= n; i++)
    {
        if (i % B != 0)
        {
            continue;
        }
        if ((n - i) % D != 0)
        {
            continue;
        }
        int cost = (i / B) * C + ((n - i) / D) * E;
        ans = min(ans, cost);
    }
    if (ans == INT_MAX)
    {
        return -1;
    }
    return ans;
}

int main()
{

    // cout<<solve(7,1,1,3,2)<<endl;

    cout << (530 % 4) << endl;

    return 0;
}
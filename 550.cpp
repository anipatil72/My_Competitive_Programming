#include <bits/stdc++.h>
using namespace std;

void recur(vector<int> &coins, int amount, int &ans, int temp)
{
    if (amount == 0)
    {
        ans = min(ans, temp);
        return;
    }

    for (int i = 0; i < coins.size(); i++)
    {
        if (amount - coins[i] >= 0)
        {
            recur(coins, amount - coins[i], ans, temp + 1);
        }
    }
}

int coinChange(vector<int> &coins, int amount)
{
    int n = coins.size();

    int ans = INT_MAX;

    int temp = 0;

    recur(coins, amount, ans, temp);

    if (ans == INT_MAX)
    {
        return -1;
    }

    return ans;
}

int main()
{

    return 0;
}
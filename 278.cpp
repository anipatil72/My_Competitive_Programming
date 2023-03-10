#include <bits/stdc++.h>
using namespace std;

void recur(vector<vector<int>> &a, vector<int> &coins, vector<int> &t, int sum, int &cur, int p)
{

    t.push_back(coins[p]);
    cur += coins[p];


    if (cur == sum)
    {
        a.push_back(t);


        t.pop_back();
        cur -= coins[p];
        return;
    }

    if (cur > sum)
    {
        t.pop_back();
        cur -= coins[p];
        return;
    }

    for (int i = p; i >= 0; i--)
    {

        recur(a, coins, t, sum, cur, i);
    }

    t.pop_back();
    cur -= coins[p];


}

vector<vector<int>> CoinCollect(vector<int> &coins, int sum)
{
    int n = coins.size();

    vector<vector<int>> ans;

    vector<int> temp;

    int current = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        recur(ans, coins, temp, sum, current, i);
    }

    return ans;
}

int main()
{

    vector<int> coins = {3,5};
    int sum = 7;

    vector<vector<int>> ans = CoinCollect(coins, sum);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }

        cout << endl;
    }


    // cout<<"There are total "<<ans.size()<<" ways"<<endl;

    return 0;
}
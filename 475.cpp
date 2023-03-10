#include <bits/stdc++.h>
using namespace std;

void recur(vector<vector<int>> &ans, vector<int> t, int k, int cur, int n)
{

    if (cur > n)
    {
        return;
    }

    if (t.size() == k)
    {
        ans.push_back(t);
        return;
    }

    // recur(ans, t, k, cur + 1, n);

    if (n - cur >= k - t.size())
    {
        recur(ans, t, k, cur + 1, n);
    }
    t.push_back(cur);
    recur(ans, t, k, cur + 1, n);
}

vector<vector<int>> combine(int n, int k)
{
    vector<vector<int>> ans;
    vector<int> temp;

    int cur = 1;

    recur(ans, temp, k, cur, n + 1);

    return ans;
}

int main()
{

    vector<vector<int>> ans = combine(5,3 );

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[0].size(); j++)
        {
            cout << ans[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}
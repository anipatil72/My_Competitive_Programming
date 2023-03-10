// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#define ll long long
#define M 1000000007
using namespace std;

int findJudge(int n, vector<vector<int>> &trust)
{
    vector<vector<int>> adj(n + 1);
    vector<vector<int>> ajd(n + 1);

    for (int i = 0; i < trust.size(); i++)
    {
        int x = trust[i][0];

        int y = trust[i][1];

        adj[x].push_back(y);

        ajd[y].push_back(x);
    }

    for (int i = 1; i <= n; i++)
    {

        if (adj[i].size() == 0 && ajd[i].size() == n - 1)
        {
            return i;
        }
    }

    return -1;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
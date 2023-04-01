// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;

class DSU
{
    vector<int> parent;

    vector<int> rank;

public:
    DSU(int n)
    {

        parent.resize(n);

        rank.resize(n);

        for (int i = 0; i < n; i++)
        {
            parent[i] = i;

            rank[i] = 0;
        }
    }

    int find(int x)
    {

        if (x == parent[x])
        {

            return x;
        }

        parent[x] = find(parent[x]);

        return parent[x];
    }

    void Union(int x, int y)
    {
        int x_rep = find(x), y_rep = find(y);

        if (x_rep == y_rep)
        {
            return;
        }

        if (rank[x] > rank[y])
        {

            parent[y_rep] = x_rep;
        }
        else if (rank[x] < rank[y])
        {
            parent[x_rep] = y_rep;
        }
        else
        {
            parent[y_rep] = x_rep;

            rank[x_rep]++;
        }
    }
    int giveConnected()
    {
        int ans = 0;

        for (int i = 0; i < parent.size(); i++)
        {
            if (parent[i] == i)
            {
                ans++;
            }
        }

        return ans;
    }
};

vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
{
    int n = accounts.size();

    DSU gap(n);

    unordered_map<string, int> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < accounts[i].size(); j++)
        {

            string mail = accounts[i][j];

            if (m.count(mail) == 0)
            {
                m[mail] = i;
            }
            else
            {
                gap.Union(i, m[mail]);
            }
        }
    }

    vector<vector<string>> merged(n);

    for (auto it : m)
    {
        string mail = it.first;

        int node = gap.find(it.second);

        merged[node].push_back(mail);
    }

    vector<vector<string>> ans;

    for (int i = 0; i < n; i++)
    {
        if (merged[i].size() == 0)
        {
        }
        else
        {
            sort(merged[i].begin(), merged[i].end());

            vector<string> temp;

            temp.push_back(accounts[i][0]);

            for (auto x : merged[i])
            {
                temp.push_back(x);
            }

            ans.push_back(temp);
        }
    }

    return ans;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
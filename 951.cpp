// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

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

int findCircleNum(vector<vector<int>> &isConnected)
{
    int n = isConnected.size();

    DSU forest(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (isConnected[i][j] == 1)
            {
                forest.Union(i, j);
            }
        }
    }

    return forest.giveConnected();
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
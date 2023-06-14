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

struct Point
{
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

int giveco(int x, int y, int n, int m)
{
    return m * x + y;
}

vector<int> numIslands2(int n, int m, vector<Point> &operators)
{
    int tot = n * m;

    vector<vector<int>> mat(n, vector<int>(m, 0));

    DSU forest(tot);

    int len = operators.size();

    vector<int> ans(len);

    int exis = 0;

    for (int i = 0; i < len; i++)
    {
        int x = operators[i].x;
        int y = operators[i].y;

        if (mat[x][y] == 1)
        {
            continue;
        }

        int des = giveco(x, y, n, m);

        unordered_set<int> s;

        if (x > 0 && mat[x - 1][y] == 1)
        {
            s.insert(forest.find(giveco(x - 1, y, n, m)));

            // forest.Union(giveco(x - 1, y, n, m), des);
        }

        if (x + 1 < n && mat[x + 1][y] == 1)
        {
            s.insert(forest.find(giveco(x + 1, y, n, m)));

            // forest.Union(giveco(x - 1, y, n, m), des);
        }

        if (y > 0 && mat[x][y - 1] == 1)
        {
            s.insert(forest.find(giveco(x, y - 1, n, m)));

            // forest.Union(giveco(x - 1, y, n, m), des);
        }

        if (y + 1 < m && mat[x][y + 1] == 1)
        {
            s.insert(forest.find(giveco(x, y + 1, n, m)));

            // forest.Union(giveco(x - 1, y, n, m), des);
        }

        exis = exis + 1 - s.size();

        ans[i] = exis;

        mat[x][y] = 1;

        if (x > 0 && mat[x - 1][y] == 1)
        {
            // s.insert(forest.find(des));

            forest.Union(giveco(x - 1, y, n, m), des);
        }

        if (x + 1 < n && mat[x + 1][y] == 1)
        {
            // s.insert(forest.find(des));

            forest.Union(giveco(x + 1, y, n, m), des);
        }

        if (y > 0 && mat[x][y - 1] == 1)
        {
            // s.insert(forest.find(des));

            forest.Union(giveco(x, y - 1, n, m), des);
        }

        if (y + 1 < m && mat[x][y + 1] == 1)
        {
            // s.insert(forest.find(des));

            forest.Union(giveco(x, y + 1, n, m), des);
        }
    }

    return ans;
}

// Input: n = 3, m = 3, A = [[0,0],[0,1],[2,2],[2,1]]
// Output: [1,1,2,2]

int main()
{

    vector<Point> a;

    Point x = Point(0, 0);
    Point y = Point(0, 1);
    Point z = Point(2, 2);
    Point w = Point(2, 1);

    a.push_back(x);
    a.push_back(y);
    a.push_back(z);
    a.push_back(w);

    vector<int> ans = numIslands2(3, 3, a);

    for (int d : ans)
    {
        cout << d << " ";
    }

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
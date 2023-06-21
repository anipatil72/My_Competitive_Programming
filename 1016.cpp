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

class TreeAncestor
{
    vector<vector<int>> v;

    vector<int> parent;

    vector<int> heights;

public:
    TreeAncestor(int n, vector<int> &parent)
    {
        parent.resize(n);

        heights.resize(n, -1);

        this->parent = parent;

        parent[0] = 0;

        v.resize(n);

        for (int i = 0; i < n; i++)
        {
            v[i].resize(20);
        }

        heights[0] = 0;

        for (int i = 1; i < n; i++)
        {
            int tt = pretest(i, heights);
        }

        parent[0] = 0;

        for (int i = 1; i < n; i++)
        {
            v[i][0] = parent[i];
        }

        for (int i = 1; i < 20; i++)
        {
            for (int j = 0; j < n; j++)
            {
                v[j][i] = v[v[j][i - 1]][i - 1];
            }
        }
    }

    int pretest(int node, vector<int> &height)
    {
        if (height[node] != -1)
        {
            return height[node];
        }

        return height[node] = pretest(parent[node], height) + 1;
    }

    int getKthAncestor(int node, int k)
    {

        if (k > heights[node])
        {
            return -1;
        }

        for (int i = 0; i < 20; i++)
        {
            if ((k & (1 << i)))
            {
                node = v[node][i];
            }
        }

        return node;
    }
};

// class TreeAncestor
// {
//     vector<int> parent;

//     int des = 0;

//     vector<vector<int>> v;

// public:
//     TreeAncestor(int n, vector<int> &parent)
//     {
//         parent.resize(n);

//         this->parent = parent;

//         v.resize(n);

//         vector<int> height(n, -1);

//         height[0] = 0;

//         for (int i = 1; i < n; i++)
//         {
//             des = max(des, pretest(i, height));
//         }

//         for (int i = 0; i < n; i++)
//         {
//             v[i].resize(des, -1);
//         }
//     }

//     int pretest(int node, vector<int> &height)
//     {
//         if (height[node] != -1)
//         {
//             return height[node];
//         }

//         return height[node] = pretest(parent[node], height) + 1;
//     }

//     int recur(int node, int k)
//     {

//         if (k > 0 && node == 0)
//         {
//             return -1;
//         }

//         if (k == 0)
//         {
//             return node;
//         }

//         if (v[node][k] != -1)
//         {
//             return v[node][k];
//         }

//         int tem = recur(parent[node], k - 1);

//         return v[node][k] = tem;
//     }

//     int getKthAncestor(int node, int k)
//     {

//         if (node == 0 || k > des)
//         {
//             return -1;
//         }

//         return recur(node, k);
//     }
// };

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
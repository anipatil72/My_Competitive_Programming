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

bool recur(int index, vector<vector<int>> &graph, vector<int> &color, int here)
{

    if (color[index] != -1)
    {
        if (color[index] != here)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    color[index] = here;

    for (int i = 0; i < graph[index].size(); i++)
    {
        bool tem = recur(graph[index][i], graph, color, !here);

        if (!tem)
        {
            return false;
        }
    }

    return true;
}

bool isBipartite(vector<vector<int>> &graph)
{
    int n = graph.size();

    vector<int> color(n, -1);

    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            bool tem = recur(i, graph, color, 1);

            if (!tem)
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
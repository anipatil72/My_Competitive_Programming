#include <bits/stdc++.h>
using namespace std;

void DFSRecur(vector<vector<int>> &a, bool v[], int s)
{

    v[s] = true;

    cout << s << " ";

    for (int i = 0; i < a[s].size(); i++)
    {
        if (v[a[s][i]] == false)
        {
            DFSRecur(a, v, a[s][i]);
        }
    }
}

void DFS(vector<vector<int>> &a, int v, int s)
{
    bool visited[v];

    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }

    DFSRecur(a, visited, s);
}

int main()
{

    vector<vector<int>> adj = {{1, 2}, {0, 3, 4}, {0, 3}, {2, 1, 4}, {1, 3}};

    DFS(adj, 5, 1);

    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

vector<vector<int>> adj; // adjacency list to represent graph
vector<bool> visited;
vector<int> ways;

void dfs(int node)
{
    visited[node] = true;

    // If we reach the last node, there is one way to reach there (the current path)
    if (node == adj.size() - 1)
    {
        ways[node] = 1;
        return;
    }

    // Otherwise, count the ways from all connected nodes
    for (auto next_node : adj[node])
    {
        if (!visited[next_node])
        {
            dfs(next_node);
        }
        ways[node] = (ways[node] + ways[next_node]) % MOD;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    adj.assign(n, vector<int>());
    visited.assign(n, false);
    ways.assign(n, 0);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--; // 0-based indexing
        b--; // 0-based indexing
        adj[a].push_back(b);
    }

    dfs(0); // start DFS from the first node

    cout << ways[0] << endl; // print the number of ways to complete the game

    return 0;
}

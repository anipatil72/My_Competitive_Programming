// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#define ll long long
#define M 1000000007
using namespace std;

void dfs(vector<vector<int>> &adj, vector<int> &visited, stack<int> &s, int node)
{
    visited[node] = 0;

    for (int i = 0; i < adj[node].size(); i++)
    {
        if (visited[adj[node][i]])
        {
            dfs(adj, visited, s, adj[node][i]);
        }
    }

    s.push(node);
}

string findOrder(string dict[], int N, int K)
{
    int n = N;

    // Topological Sort of the the order 

    vector<vector<int>> adj(K);

    for (int i = 0; i < n - 1; i++)
    {
        string fir = dict[i];

        string sec = dict[i + 1];

        int len = min(fir.length(), sec.length());

        for (int j = 0; j < len; j++)
        {
            if (fir[j] == sec[j])
            {
            }
            else
            {
                adj[fir[j] - 'a'].push_back(sec[j] - 'a');

                break;
            }
        }
    }

    vector<int> visited(K, 1);

    stack<int> s;

    for (int i = 0; i < K; i++)
    {

        if (visited[i])
        {
            dfs(adj, visited, s, i);
        }
    }

    string ans = "";

    while (!s.empty())
    {
        char t = 'a' + s.top();

        s.pop();

        ans += t;
    }

    return ans;
}

int main()
{

    // char t = 'a' + 25;

    // cout << t << endl;

    string v[] = {"caa","aaa","aab"};

    cout << findOrder(v, 3, 3);

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
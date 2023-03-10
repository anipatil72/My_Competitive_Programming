// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

// Node *recur(Node *node, vector<int> &visited)
// {
//     if (!visited[node->val])
//     {
//         return NULL;
//     }

//     Node *nnode = new Node(node->val);

//     nnode->neighbors = node->neighbors;

//     for (int i = 0; i < node->neighbors.size(); i++)
//     {
//         nnode->neighbors.push_back(recur(node->neighbors[i], visited));
//     }

//     visited[node->val] = 0;
// }

void recur(vector<vector<int>> &adj, vector<int> &visited, Node *node)
{
    if (visited[node->val] == 0)
    {
        return;
    }

    int d = node->val;

    visited[d] = 0;

    for (int i = 0; i < node->neighbors.size(); i++)
    {

        int x = node->neighbors[i]->val;

        if (visited[x] == 0)
        {
            adj[i].push_back(x);
        }
        else
        {

            adj[i].push_back(x);

            recur(adj, visited, node->neighbors[i]);
        }
    }
}

Node *cloneGraph(Node *node)
{

    vector<int> visited(101, 1);

    vector<int> v;

    vector<vector<int>> adj(101, v);

    vector<Node *> add(101, NULL);

    for (int i = 0; i < 101; i++)
    {
        if (!visited[i])
        {
            Node *nnode = new Node(i);

            add[i] = node;
        }
    }

    for (int i = 0; i < adj.size(); i++)
    {

        for (int j = 0; j < adj[i].size(); j++)
        {
            add[i]->neighbors.push_back(add[adj[i][j]]);
        }
    }

    return add[node->val];

    // return recur(node, visited);
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
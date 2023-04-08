// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;

// Definition for a Node.
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

Node *dfs(Node *cur, unordered_map<int, Node *> &m)
{
    // n = max(cur->val, n);

    Node *newnode = new Node(cur->val);

    m[cur->val] = newnode;

    for (int i = 0; i < cur->neighbors.size(); i++)
    {

        if (m.count(cur->neighbors[i]->val) == 0)
        {
            newnode->neighbors.push_back(dfs(cur->neighbors[i], m));
        }
        else
        {
            newnode->neighbors.push_back(m[cur->neighbors[i]->val]);
        }
    }

    return newnode;
}

Node *cloneGraph(Node *node)
{
    if (node == NULL)
    {
        return NULL;
    }

    unordered_map<int, Node *> m;

    // Node *beg = new Node(node->val);

    // m[beg->val] = beg;

    Node *beg = dfs(node, m);

    // int tot = 0;

    // dfs(node, tot, m);

    // vector<Node *> newGraph(tot, NULL);

    // newGraph[(beg->val) - 1] = beg;

    return beg;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
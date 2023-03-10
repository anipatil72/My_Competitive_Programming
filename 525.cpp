#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

vector<vector<int>> levelOrder(Node *root)
{
    if (root == NULL)
    {
        return {};
    }

    queue<Node *> q;

    vector<vector<int>> ans;

    vector<int> temp;

    // ans.push_back({root->val});

    q.push(root);

    q.push(NULL);

    while (!q.empty())
    {
        Node *t = q.front();

        q.pop();

        if (t == NULL)
        {
            ans.push_back(temp);

            temp.clear();

            if (!q.empty())
            {
                q.push(NULL);
            }

            continue;
        }

        temp.push_back(t->val);

        for (int i = 0; i < t->children.size(); i++)
        {
            q.push(t->children[i]);
        }
    }

    return ans;
}

int main()
{

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> levelOrder(TreeNode *root)
{

    vector<vector<int>> v;

    if (root == NULL)
    {
        return v;
    }

    queue<TreeNode *> q;

    q.push(root);

    q.push(NULL);
    vector<int> p;

    while (!q.empty())
    {

        TreeNode *t = q.front();

        q.pop();

        if (t == NULL)
        {
            v.push_back(p);
            p.clear();
            if (!q.empty())
            {
                q.push(NULL);
            }

            continue;
        }

        p.push_back(t->val);

        if (t->left != NULL)
        {
            q.push(t->left);
        }

        if (t->right != NULL)
        {
            q.push(t->right);
        }
    }

    return v;
}

int main()
{

    return 0;
}
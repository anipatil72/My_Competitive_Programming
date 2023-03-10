#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *helper(TreeNode *r, TreeNode *p, TreeNode *q)
{

    if (r == NULL)
    {
        return NULL;
    }

    if (r == p || r == q)
    {
        return r;
    }

    if (r->val < min(p->val, q->val))
    {
        return helper(r->right, p, q);
    }

    if (r->val > max(p->val, q->val))
    {
        return helper(r->left, p, q);
    }

    return r;
}

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{

    if (root == NULL)
    {
        return NULL;
    }

    if (root == p || root == q)
    {
        return root;
    }

    return helper(root, p, q);
}

int main()
{

    return 0;
}
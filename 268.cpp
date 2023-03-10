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

TreeNode *helper(int ps, int pe, int is, int ie, vector<int> &preorder, vector<int> &inorder)
{

    if (is > ie || ps > pe)
    {
        return NULL;
    }

    int rootIndex = -1;

    int r = preorder[ps];

    for (int i = is; i < ie; i++)
    {
        if (inorder[i] == r)
        {
            rootIndex = i;
            break;
        }
    }

    TreeNode *root = new TreeNode(r);

    int pls, ple, prs, pre, ils, ile, irs, ire;

    pls = ps + 1;
    pre = pe;

    ils = is;
    ile = rootIndex - 1;
    irs = rootIndex + 1;
    ire = ie;
    ple = ile -ils + pls;
    prs = ple + 1;

    root->left = helper(pls, ple, ils, ile, preorder, inorder);
    root->right = helper(prs, pre, irs, ire, preorder, inorder);

    return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    if (preorder.size() == 0)
    {
        return NULL;
    }

    if (preorder.size() == 1)
    {
        TreeNode *root = new TreeNode(preorder[0]);
        root->left = NULL;
        root->right = NULL;
        return root;
    }

    TreeNode *root = helper(0, preorder.size() - 1, 0, inorder.size() - 1, preorder, inorder);

    return root;
}

int main()
{

    return 0;
}
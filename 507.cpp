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

bool isSymmetric(TreeNode *root)
{

    if (root == NULL)
    {
        return true;
    }

    if (root->left == NULL && root->right != NULL)
    {
        return false;
    }

    if (root->left != NULL && root->right == NULL)
    {
        return false;
    }

    return (root->left->val == root->right->val) && (isSymmetric(root->right) && isSymmetric(root->left));
}

int main()
{

    return 0;
}
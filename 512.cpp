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

void recur(TreeNode *r, vector<int> &v)
{
    if (r == NULL)
    {
        return;
    }

    v.push_back(r->val);

    recur(r->left, v);
    recur(r->right, v);
}

vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> v;

    if (root == NULL)
    {
        return v;
    }

    recur(root, v);

    return v;
}

bool hasPathSum(TreeNode *root, int targetSum)
{

    
}

int main()
{

    return 0;
}
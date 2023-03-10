// ॥ श्री गणेशाय नमः ॥

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

bool isLeaf(TreeNode *r)
{
    if (r == NULL)
    {
        return false;
    }

    return (r->left == NULL) && (r->right == NULL);
}

void recur(TreeNode *r, int &sum, TreeNode *root)
{

    if (r == NULL)
    {
        return;
    }

    if (isLeaf(r->left) && r != root)
    {

        sum += r->left->val;

        recur(r->right, sum, root);

        return;
    }
    else
    {
        recur(r->left, sum, root);
        recur(r->right, sum, root);
    }
}

int sumOfLeftLeaves(TreeNode *root)
{

    int ans = 0;

    recur(root, ans, root);

    return ans;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
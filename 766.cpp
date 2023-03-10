// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define M 1000000007
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

int recur(TreeNode *root)
{
    if (root == NULL)
    {
        return 1;
    }

    return 1 + max(recur(root->left), recur(root->left));
}

int maxDepth(TreeNode *root)
{
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
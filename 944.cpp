// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool recur(TreeNode *root, int sum)
{
    if (root->left == NULL && root->right != NULL)
    {
        return recur(root->right, sum - root->val);
    }
    else if (root->left != NULL && root->right == NULL)
    {
        return recur(root->left, sum - root->val);
    }
    else if (root->left == NULL && root->right == NULL)
    {
        return sum == root->val;
    }

    return recur(root->left, sum - root->val) || recur(root->right, sum - root->val);
}

bool hasPathSum(TreeNode *root, int targetSum)
{
    if (root == NULL)
    {
        return false;
    }

    return recur(root, targetSum);
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
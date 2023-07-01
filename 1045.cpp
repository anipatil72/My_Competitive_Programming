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

bool recur(TreeNode *root, int target)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (root == NULL)
    {
        return false;
    }

    if (root->left == NULL && root->right == NULL)
    {
        if (root->val == target)
        {
            return true;
        }

        return false;
    }

    bool lef = recur(root->left, target);

    bool rig = recur(root->right, target);

    if (lef)
    {
        TreeNode *tem = root->left;
        root->left = NULL;

        delete (tem);
    }

    if (rig)
    {
        TreeNode *tem = root->right;
        root->right = NULL;

        delete (tem);
    }

    if (root->left == NULL && root->right == NULL)
    {
        if (root->val == target)
        {
            return true;
        }
    }

    return false;
}

TreeNode *removeLeafNodes(TreeNode *root, int target)
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    bool ans = recur(root, target);

    if (ans)
    {
        delete (root);

        return NULL;
    }

    return root;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
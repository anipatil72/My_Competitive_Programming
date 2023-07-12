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

void setParents(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &m)
{
    if (root == NULL)
    {
        return;
    }

    if (root->left != NULL)
    {
        m[root->left] = root;
    }

    if (root->right != NULL)
    {
        m[root->right] = root;
    }

    setParents(root->left, m);

    setParents(root->right, m);
}

void recur(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &m, vector<int> &ans, int cur, TreeNode *parent)
{
    if (root == NULL)
    {
        return;
    }

    if (cur == 0)
    {
        ans.push_back(root->val);

        return;
    }

    if (root->left != NULL && (root->left != parent))
    {
        recur(root->left, m, ans, cur - 1, root);
    }

    if (root->right != NULL && (root->right != parent))
    {
        recur(root->right, m, ans, cur - 1, root);
    }

    TreeNode *par = m[root];

    if (par != NULL && (par != parent))
    {
        recur(par, m, ans, cur - 1, root);
    }
}

vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
{
    if (root == NULL)
    {
        return {};
    }

    unordered_map<TreeNode *, TreeNode *> m;

    m[target] = NULL;

    setParents(root, m);

    vector<int> ans;

    recur(target, m, ans, k, NULL);

    return ans;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
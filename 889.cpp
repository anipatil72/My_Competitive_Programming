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

int recur(TreeNode *root, map<pair<TreeNode *, int>, int> &m, int tall)
{
    if (root == NULL)
    {
        return 0;
    }

    if (m.find({root, tall}) != m.end())
    {
        return m[{root, tall}];
    }

    int take = (int)(-1e9);

    if (tall == 1)
    {
        take = root->val + recur(root->left, m, 0) + recur(root->right, m, 0);
    }

    int nottake = recur(root->left, m, 1) + recur(root->right, m, 1);

    return m[{root, tall}] = max(take, nottake);
}

int rob(TreeNode *root)
{

    map<pair<TreeNode *, int>, int> m;

    return recur(root, m, 1);
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
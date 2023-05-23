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

TreeNode *recur(TreeNode *root, vector<TreeNode *> &ans, vector<int> &del, bool check)
{
    if (root == NULL)
    {
        return NULL;
    }

    bool b = binary_search(del.begin(), del.end(), root->val);

    if (b)
    {

        // if (lef != NULL)
        // {
        //     ans.push_back(lef);
        // }

        // if (rig != NULL)
        // {
        //     ans.push_back(rig);
        // }
        TreeNode *lef = recur(root->left, ans, del, b);

        TreeNode *rig = recur(root->right, ans, del, b);

        // ans.push_back(rig);

        return NULL;
    }

    TreeNode *lef = recur(root->left, ans, del, b);

    TreeNode *rig = recur(root->right, ans, del, b);

    root->left = lef;

    root->right = rig;

    if (!b && (check))
    {
        ans.push_back(root);
    }

    return root;
}

vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete)
{
    vector<TreeNode *> ans;

    TreeNode *tem = recur(root, ans, to_delete, 1);

    return ans;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
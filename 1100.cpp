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

bool checkLeaf(TreeNode *des)
{
    return (des->right == NULL && des->left == NULL);
}

void recur(TreeNode *root, int &ans, string s)
{
    if (root == NULL)
    {
        return;
    }

    if (checkLeaf(root))
    {
        s += to_string(root->val);

        ans += stoll(s);

        return;
    }

    string tem = s;

    tem += to_string(root->val);

    recur(root->left, ans, tem);
    recur(root->right, ans, tem);
}

int sumNumbers(TreeNode *root)
{
    int ans = 0;

    string s = "";

    recur(root, ans, s);

    return ans;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
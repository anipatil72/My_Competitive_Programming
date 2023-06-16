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

void recur(TreeNode *root, int &levelx, int &levely, int x, int y, int curlevel, bool &check)
{
    if (root == NULL)
    {
        return;
    }

    if (root->val == x)
    {
        levelx = curlevel;
    }

    if (root->val == y)
    {
        levely = curlevel;
    }

    if (root->left != NULL && root->right != NULL)
    {
        if ((root->left->val == x && root->right->val == y) || (root->left->val == y && root->right->val == x))
        {
            check = true;
        }
    }

    recur(root->left, levelx, levely, x, y, curlevel + 1, check);
    recur(root->right, levelx, levely, x, y, curlevel + 1, check);
}

bool isCousins(TreeNode *root, int x, int y)
{

    int levelx = -1, levely = -1;

    bool checksiblings = 0;

    recur(root, levelx, levely, x, y, 0, checksiblings);

    cout << levelx << " " << levely << " " << checksiblings << endl;

    return (levelx == levely) && (!checksiblings);
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
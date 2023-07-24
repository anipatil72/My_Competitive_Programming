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

bool isLeaf(TreeNode *root)
{
    return (root->left == NULL && root->right == NULL);
}

void recur(TreeNode *root, string &s, string &mini)
{
    if (root == NULL)
    {
        return;
    }

    char d = (char)('a' + root->val);

    s += d;

    if (isLeaf(root))
    {

        string tem = s;

        reverse(tem.begin(), tem.end());

        if (mini == "")
        {
            mini = tem;
        }
        else if (mini > tem)
        {
            mini = tem;
            // mini = min(tem, ni);
        }

        s.pop_back();

        return;
    }

    recur(root->left, s, mini);

    recur(root->right, s, mini);

    s.pop_back();
}

string smallestFromLeaf(TreeNode *root)
{

    string ans = "";

    string tem = "";

    recur(root, tem, ans);

    return ans;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
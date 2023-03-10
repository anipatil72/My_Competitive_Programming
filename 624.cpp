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

void recur(TreeNode *r, vector<string> &ans, string temp)
{
    if (r == NULL)
    {
        return;
    }

    if (r->left == NULL && r->right == NULL)
    {
        temp+= to_string(r->val);
        ans.push_back(temp);

        return;
    }

    temp += to_string(r->val) + "->";

    recur(r->left, ans, temp);
    recur(r->right, ans, temp);
}

vector<string> binaryTreePaths(TreeNode *root)
{
    vector<string> ans;

    string t = "";

    recur(root, ans, t);

    return ans;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
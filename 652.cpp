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

void recur(TreeNode *r, vector<int> &lvs)
{
    if (r == NULL)
    {
        return;
    }

    recur(r->left, lvs);
    recur(r->right, lvs);

    if ((r->left == NULL) && (r->right == NULL))
    {
        lvs.push_back(r->val);
    }
}

bool leafSimilar(TreeNode *root1, TreeNode *root2)
{
    vector<int> lvs1;
    vector<int> lvs2;

    recur(root1, lvs1);
    recur(root2, lvs2);

    return lvs1 == lvs2;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
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

void recur(vector<int>& v,TreeNode* r)
{
    if (r==NULL)
    {
            return;
    }

    recur(v,r->left);
    v.push_back(r->val);
    recur(v,r->right);
    
}

vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> ans;

    recur(ans,root);
}

int main()
{

    return 0;
}
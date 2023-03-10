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

void recur(TreeNode* p, TreeNode* q, TreeNode* root)
{
    
}

void recoverTree(TreeNode *root)
{
    if (root == NULL)
    {
        return ;
    }

    TreeNode* t = root,p = NULL,q = NULL;







}

int main()
{

    return 0;
}
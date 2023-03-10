#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* recur(TreeNode* root,TreeNode* p,TreeNode* q)
{
    if (root==NULL)
    {
         return NULL;   
    }

    if (root->val==p->val)
    {
        return p;
    }


    if (root->val==q->val)
    {
        return q;
    }

    TreeNode* x = recur(root->left,p,q);
    TreeNode* y = recur(root->right,p,q);

    if (x==NULL&&y!=NULL)
    {
         return recur(root->right,p,q);   
    }

    if (y==NULL&&x!=NULL)
    {
         return recur(root->left,p,q);   
    }

    if (y ==NULL&&x==NULL)
    {
         return NULL;   
    }
    

    return root;

}

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{

    

    //There we go private
    return recur(root,p,q);
    
}

int main()
{

    return 0;
}
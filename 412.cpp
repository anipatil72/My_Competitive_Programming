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

bool isValidBST(TreeNode* r)
{
    if (r==NULL)
    {
            return true;
    }

    int d = r->val;


    if (r->left!=NULL&&r->right!=NULL)
    {
        
         return isValidBST(r->left)&&isValidBST(r->right)&&((d < r->right->val)&&(d>r->left->val));
    }

    if (r->left==NULL&&r->right!=NULL)
    {
        return isValidBST(r->left)&&isValidBST(r->right)&&((d < r->right->val))  ; 
    }


    if (r->left!=NULL&&r->right==NULL)
    {
        return isValidBST(r->left)&&isValidBST(r->right)&&((d > r->left->val))  ; 
    }
    
    
    return true;
}



int main()
{

    return 0;
}
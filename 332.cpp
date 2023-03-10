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

void recur(TreeNode *r, vector<int> &v)
{
    if (r == NULL)
    {
        return;
    }

    // TreeNode *newnode = new TreeNode(r->val);

    v.push_back(r->val);

    recur(r->left, v);
    recur(r->right, v);

    // delete r;
}

void flatten(TreeNode *root)
{
    // TreeNode* Root = new TreeNode(root->val);

    // int rootdata = root->val;

   TreeNode *curr=root;
        TreeNode * prev;
        while(curr!=NULL)
        {
            if(curr->left!=NULL)
            {
                prev=curr->left;
                while(prev->right!=NULL)
                {
                    prev=prev->right;
                }
                prev->right=curr->right;
                curr->right=curr->left;
                curr->left=NULL;
            }
            curr=curr->right;
            
        }
        return;
    
    // cout<<root->right->right->right->right->right->val<<endl;

    // root = t;
}

int main()
{

    return 0;
}
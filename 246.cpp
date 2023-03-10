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

// void Recur(vector<int> &v, TreeNode *r)
// {
//     if (r == NULL)
//     {
//         return;
//     }

//     v.push_back(r->val);

//     Recur(v, r->right);
//     if (r->right==NULL)
//     {
//         Recur(v,r->left);
//     }
// }

vector<int> rightSideView(TreeNode *root)
{

    vector<int> v;


    if (root==NULL)
    {
            return v ;
    }
    
    TreeNode *prev = root;

    queue<TreeNode *> q;
    q.push(root);
    q.push(NULL);
    v.push_back(root->val);

    while (!q.empty())
    {

        TreeNode *t = q.front();
        q.pop();

        if (t == NULL)
        {

            v.push_back(prev->val);

            if (!q.empty())
            {
                q.push(NULL);
                    
            }
            
            continue;
        }

        if (t->left != NULL)
        {
            q.push(t->left);
            prev = t->left;
        }

        if (t->right != NULL)
        {
            q.push(t->right);
            prev = t->right;
        }
    }


    v.pop_back();

    return v;
}

int main()
{

    return 0;
}
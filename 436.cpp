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

bool recur(TreeNode* p, TreeNode* q)
{
  if (p==NULL&&q!=NULL)
  {
        return false;
  }

  if (p!=NULL&&q==NULL)
  {
        return false;
  }

  if (p==NULL&&q==NULL)
  {
        return true;
  }


  return (p->val==q->val)&&(recur(p->left,q->left))&&(recur(p->right,q->right));
  
    
}

bool isSameTree(TreeNode *p, TreeNode *q)
{

    recur(p,q);


}

int main()
{

    return 0;
}
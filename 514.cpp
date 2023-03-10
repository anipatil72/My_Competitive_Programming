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

void recur(TreeNode *r, vector<int> &v, int &count)
{
    if (r == NULL)
    {
        return;
    }

    if (v.size()!=0&&(*max_element(v.begin(), v.end()) <= r->val))
    {
        count++;
    }
    else if (v.size()==0)
    {
        count++;
    }
    

    v.push_back(r->val);

    recur(r->left, v, count);
    recur(r->right, v, count);

    v.pop_back();
}

int goodNodes(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int count = 0;

    vector<int> v;

    recur(root,v,count);

    cout<<count<<endl;


    return count;
}

int main()
{

    vector<int> v = {};

    int d = 4;

    if (*max_element(v.begin(),v.end())<=d)
    {
        cout<<"Yes it is possible !!";    
    }
    else
    {
        cout<<"Sorry !! Try another way";
    }
    
    

    return 0;
}
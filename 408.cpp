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

TreeNode *recur(vector<int> &v, int s, int e)
{

    if (s > e)
    {
        return NULL;
    }

    int root = (e+s)/2;

    int ls = 0, le = root - 1, rs = root + 1, re = e;

    TreeNode *r = new TreeNode(v[root]);

    r->left = recur(v, ls, le);
    r->right = recur(v, rs, re);

    return r;
}

TreeNode *sortedArrayToBST(vector<int> &nums)
{

    int n = nums.size();

    int start = 0, int end = n - 1;


    TreeNode* root = recur(nums,start,end);


    return root;
}

//-10,-3,0,5,9

int main()
{

    return 0;
}
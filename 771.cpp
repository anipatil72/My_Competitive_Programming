// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define M 1000000007
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

void recur(TreeNode *root, vector<int> &a)
{
    if (root == NULL)
    {
        return;
    }

    recur(root->left, a);

    a.push_back(root->val);

    recur(root->right, a);
}

int minDiffInBST(TreeNode *root)
{
    int cur = -1, prev = -1;

    int ans = INT_MAX;

    vector<int> a;

    recur(root, a);

    int n = a.size();

    for (int i = 0; i < n - 1; i++)
    {
        ans = min(ans, abs(a[i] - a[i + 1]));
    }

    return ans;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
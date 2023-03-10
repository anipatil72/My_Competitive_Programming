// ॥ श्री गणेशाय नमः ॥

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

void recur(vector<int> &v, int &a, TreeNode *r)
{
    if (r == NULL)
    {
        return;
    }

    v.push_back(r->val);

    recur(v, a, r->left);
    recur(v, a, r->right);

    int x = *min_element(v.begin(), v.end());
    int y = *max_element(v.begin(), v.end());

    a = max(a, abs(y - x));

    v.pop_back();
}

int maxAncestorDiff(TreeNode *root)
{

    vector<int> temp;

    int ans = INT_MIN;

    recur(temp, ans, root);

    return ans;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
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

int recur(TreeNode *r, unordered_map<int, int> &mine)
{
    int sum = 0;

    sum += r->val;

    if (r->left != NULL)
    {
        sum += recur(r->left, mine);
    }

    if (r->right != NULL)
    {
        sum += recur(r->right, mine);
    }

    mine[sum]++;

    return sum;
}

vector<int> findFrequentTreeSum(TreeNode *root)
{
    int maxi = INT_MIN;

    unordered_map<int, int> mine;

    int tt = recur(root, mine);

    for (auto x : mine)
    {
        maxi = max(maxi, x.second);
    }

    vector<int> ans;

    for (auto x : mine)
    {
        if (x.second == maxi)
        {
            ans.push_back(x.first);
        }
    }

    return ans;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
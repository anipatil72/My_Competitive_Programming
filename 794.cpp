// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
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

bool isCompleteTree(TreeNode *root)
{

    if (root == NULL)
    {
        return true;
    }

    queue<TreeNode *> q;

    q.push(root);

    while (!q.empty())
    {
        auto t = q.front();

        q.pop();

        if (t == NULL)
        {
            break;
        }

        q.push(t->left);
        q.push(t->right);
    }

    while (!q.empty())
    {
        auto tem = q.front();

        q.pop();

        if (tem != NULL)
        {
            return false;
        }
    }

    return true;
}

// We are done here

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
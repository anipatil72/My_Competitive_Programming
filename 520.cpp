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

vector<double> averageOfLevels(TreeNode *root)
{
    if (root == NULL)
    {

        return {};
    }

    vector<double> ans;

    queue<TreeNode *> q;

    q.push(root);

    q.push(NULL);

    double sum = 0;

    int count = 0;

    while (!q.empty())
    {
        TreeNode *t = q.front();

        q.pop();

        if (t == NULL)
        {

            sum = sum / count;

            ans.push_back(sum);

            sum = 0;

            count = 0;

            if (!q.empty())
            {
                q.push(NULL);
            }

            continue;
        }

        count++;

        sum += t->val;

        if (t != NULL && t->left != NULL)
        {
            q.push(t->left);
        }

        if (t != NULL && t->right != NULL)
        {
            q.push(t->right);
        }
    }

    return ans;
}

int main()
{

    return 0;
}
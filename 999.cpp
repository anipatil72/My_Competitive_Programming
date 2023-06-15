// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int maxLevelSum(TreeNode *root)
{

    if (root == NULL)
    {
        return 0;
    }

    queue<TreeNode *> q;

    q.push(root);

    q.push(NULL);

    long long ans = INT_MIN;

    long long sum = 0;

    int level = 0;

    int fin = 0;

    while (!q.empty())
    {
        TreeNode *tem = q.front();

        q.pop();

        if (tem == NULL)
        {
            if (q.empty())
            {
            }
            else
            {

                q.push(NULL);
            }

            level++;

            // ans = max(sum, ans);

            if (ans < sum)
            {
                ans = sum;

                fin = level;
            }

            sum = 0;

            continue;
        }

        sum += tem->val;

        if (tem->left != NULL)
        {
            q.push(tem->left);
        }

        if (tem->right != NULL)
        {
            q.push(tem->right);
        }
    }

    return fin;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
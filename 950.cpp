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

struct Node
{
    int data;

    Node *left, *right;

    Node(int val)
    {
        this->data = val;
    }
};

bool isBST(Node *root)
{
    if (root == NULL)
    {
        return true;
    }

    if (root->left == NULL && root->right == NULL)
    {
        return true;
    }

    if (root->left == NULL && root->right != NULL)
    {
        return (root->data > (root->right->data)) && isBST(root->right);
    }

    if (root->right == NULL && root->left != NULL)
    {
        return (root->data < (root->left->data)) && isBST(root->left);
    }

    return (root->data > (root->left->data) && (root->data < (root->right->data))) && isBST(root->left) && isBST(root->right);
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
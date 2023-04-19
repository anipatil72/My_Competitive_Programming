// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;
using namespace __gnu_pbds;

class Node
{

    int data;

    Node *left;

    Node *right;

    Node(int val)
    {
        this->data = val;

        this->left = NULL;

        this->right = NULL;
    }
};

vector<int> recur(Node *root)
{
    if (root == NULL)
    {
        return {};
    }

    // vector will contain {sum of this tree, isBalanced, number of nodes}

    // if ()
    // {

    // }
}

int minSubtreeSumBST(int target, Node *root)
{
    if (root == NULL)
    {
        return -1;
    }

    //
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
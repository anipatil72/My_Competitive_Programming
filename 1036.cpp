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

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

bool leaf(Node *a)
{
    return (a->left == NULL && a->right == NULL);
}

Node *connect(Node *root)
{

    if (root == NULL)
    {
        return NULL;
    }

    queue<Node *> q;

    q.push(root);

    q.push(NULL);

    // root->next = NULL;

    Node *prev = root;

    while (!q.empty())
    {
        Node *now = q.front();

        q.pop();

        if (now != NULL && !leaf(now))
        {
            if (now->left != NULL)
            {
                q.push(now->left);
            }

            if (now->right != NULL)
            {
                q.push(now->right);
            }
        }

        if (now == NULL)
        {
            q.push(NULL);
        }

        if (now == NULL && prev == NULL)
        {
            break;
        }

        if (prev != NULL)
        {
            prev->next = now;
        }

        prev = now;
    }

    return root;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
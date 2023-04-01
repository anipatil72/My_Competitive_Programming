// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    int patil = 1;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

Node *connect(Node *root)
{
    if (root == NULL)
    {
        return NULL;
    }

    queue<Node *> q;

    q.push(root);

    q.push(NULL);

    root->next = NULL;

    Node *prev = root;

    while (!q.empty())
    {
        Node *now = q.front();

        q.pop();

        if (now)
        {
            q.push(now->left);
            q.push(now->right);
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
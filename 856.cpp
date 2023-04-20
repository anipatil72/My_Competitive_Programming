// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;
using namespace __gnu_pbds;

struct Node
{
    int data;
    Node *left;
    Node *right;

public:
    Node(int val)
    {
        this->data = val;

        this->left = NULL;
        this->right = NULL;
    }
};

// Solved it Achha Sawal tha

void indentifyNode(unordered_map<int, Node *> &m, Node *root)
{
    if (root == NULL)
    {
        return;
    }

    m[root->data] = root;

    indentifyNode(m, root->left);
    indentifyNode(m, root->right);
}

void identifyParent(unordered_map<int, Node *> &parent, Node *root, Node *cur, Node *par)
{
    if (cur == NULL)
    {
        return;
    }

    if (cur == root)
    {
        parent[cur->data] = NULL;
    }
    else
    {
        parent[cur->data] = par;
    }

    identifyParent(parent, root, cur->left, cur);
    identifyParent(parent, root, cur->right, cur);
}

void recur(Node *now, long long &ans, unordered_map<int, Node *> &parent, int steps, int k, Node *predecessor)
{
    if (steps > k)
    {
        return;
    }

    if (now == NULL)
    {
        return;
    }

    // cout << "I am here and here is my data : " << now->data << endl;

    ans += now->data;

    if (now->left != predecessor)
    {

        recur(now->left, ans, parent, steps + 1, k, now);
    }

    if (now->right != predecessor)
    {

        recur(now->right, ans, parent, steps + 1, k, now);
    }

    if (parent[now->data] != predecessor)
    {
        recur(parent[now->data], ans, parent, steps + 1, k, now);
    }
}

int ladoos(Node *root, int home, int k)
{

    if (root == NULL)
    {
        return 0;
    }

    unordered_map<int, Node *> m;
    unordered_map<int, Node *> parent;

    indentifyNode(m, root);

    identifyParent(parent, root, root, NULL);

    Node *now = m[home];

    long long ans = 0;

    // ans += home;

    recur(now, ans, parent, 0, k, NULL);

    return ans;
}

int main()
{

    Node *root = new Node(5);

    Node *firlef = new Node(3);
    Node *firrig = new Node(6);
    Node *seclef = new Node(1);
    Node *secrig = new Node(4);
    Node *firriglef = new Node(10);

    root->left = firlef;

    root->right = firrig;

    firlef->left = seclef;
    firlef->right = secrig;

    firrig->right = firriglef;

    cout << "This is ans : " << ladoos(root, 4, 2) << endl;

    return 0;
}

// 5 3 6 1 4 N 10
// 4 2

// ॥ जय श्री राम जय श्री कृष्ण ॥
#include <bits/stdc++.h>
using namespace std;

class BTreeNode
{
public:
    int data;
    BTreeNode *left;
    BTreeNode *right;

    BTreeNode(int d)
    {
        this->data = d;
    }

    ~BTreeNode()
    {
        delete left;
        delete right;
    }
};

pair<int, int> minMax(BTreeNode *r)
{
    if (r == NULL)
    {
        pair<int, int> p;

        p.first = INT_MAX;
        p.second = INT_MIN;

        return p;
    }

    pair<int, int> p1 = minMax(r->left);
    pair<int, int> p2 = minMax(r->right);

    pair<int, int> p3;
    p3.second = max(r->data, max(p1.second, p2.second));

    p3.first = min(r->data, min(p1.first, p2.first));

    return p3;
}

class BST
{

public:
    BTreeNode *root;
    BTreeNode *InsertE(BTreeNode *r, int key)
    {
        if (r == NULL)
        {
            BTreeNode *t = new BTreeNode(key);
            t->left = NULL;
            t->right = NULL;
            return t;
        }

        if (r->data < key)
        {
            r->right = InsertE(r->right, key);
            return r;
        }

        if (r->data > key)
        {
            r->left = InsertE(r->left, key);
        }

        return r;
    }

    BTreeNode *DeleteN(BTreeNode *r, int key)
    {
        if (r == NULL)
        {
            return NULL;
        }

        if (r->data > key)
        {
            r->left = DeleteN(r->left, key);
            return r;
        }

        if (r->data < key)
        {
            r->right = DeleteN(r->right, key);
            return r;
        }

        if (r->data == key && r->left == NULL && r->right != NULL)
        {
            BTreeNode *temp = r->right;
            r->right = NULL;
            delete r;
            return temp;
        }
        if (r->data == key && r->right == NULL && r->left != NULL)
        {
            BTreeNode *temp = r->left;
            r->left = NULL;
            delete r;
            return temp;
        }

        if (r->data == key && r->left == NULL && r->right == NULL)
        {
            delete r;
            return NULL;
        }

        if (r->data == key && r->left != NULL && r->right != NULL)
        {
            int replacement = minMax(r->right).first;

            r->data = replacement;

            r->right = DeleteN(r->right, replacement);
        }

        return r;
    }
};

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        this->data = d;
    }
};

vector<Node *> v;

BTreeNode *takeInputL()
{
    int rootd;

    cout << "Enter root data" << endl;
    cin >> rootd;

    BTreeNode *root = new BTreeNode(rootd);
    queue<BTreeNode *> pendingnodes;
    pendingnodes.push(root);

    while (pendingnodes.size() != 0)
    {

        BTreeNode *t = pendingnodes.front();
        pendingnodes.pop();

        cout << "Enter the left child of " << t->data << endl;
        int leftd;
        cin >> leftd;
        if (leftd != -1)
        {

            BTreeNode *left = new BTreeNode(leftd);
            t->left = left;

            pendingnodes.push(left);
        }

        if (leftd == -1)
        {
            t->left = NULL;
        }

        cout << "Enter the right child of " << t->data << endl;
        int rightd;
        cin >> rightd;
        if (rightd != -1)
        {

            BTreeNode *right = new BTreeNode(rightd);
            t->right = right;

            pendingnodes.push(right);
        }

        if (rightd == -1)
        {
            t->right = NULL;
        }
    }

    return root;
}

void PrintTL(BTreeNode *r)
{
    if (r == NULL)
    {
        return;
    }

    queue<BTreeNode *> q;

    q.push(r);

    while (q.size() != 0)
    {
        BTreeNode *t = q.front();
        q.pop();
        cout << t->data << ": ";

        if (t->left != NULL)
        {
            cout << "L " << t->left->data << ", ";
            q.push(t->left);
        }

        if (t->right != NULL)
        {
            cout << "R " << t->right->data;
            q.push(t->right);
        }

        cout << endl;
    }
}

int Mid(int startIndex, int EndIndex)
{
    return (startIndex + EndIndex) / 2;
}

BTreeNode *MakeBST(int a[], int startIndex, int EndIndex)
{

    if (startIndex > EndIndex)
    {
        return NULL;
    }

    BTreeNode *root = new BTreeNode(a[Mid(startIndex, EndIndex)]);

    root->left = MakeBST(a, startIndex, Mid(startIndex, EndIndex) - 1);

    root->right = MakeBST(a, Mid(startIndex, EndIndex) + 1, EndIndex);

    return root;
}

void BSTtoLL(BTreeNode *r)
{

    if (r == NULL)
    {

        return;
    }

    BSTtoLL(r->left);
    Node *root = new Node(r->data);

    v.push_back(root);
    BSTtoLL(r->right);
}

void PrintPath(BTreeNode *r, int k)
{

    if (r == NULL)
    {
        return;
    }

    if (r->data < k)
    {

        cout << r->data << " ";

        PrintPath(r->right, k);
        return;
    }
    if (r->data > k)
    {

        cout << r->data << " ";
        PrintPath(r->left, k);
        return;
    }

    if (r->data == k)
    {
        cout << r->data << " ";
        return;
    }
}

void CreateD(BTreeNode*& r)
{
    if (r==NULL)
    {
            return ;
    }

    CreateD(r->left);
    CreateD(r->right);

    BTreeNode* NewNode = new BTreeNode(r->data);
    NewNode->right = NULL ;
    NewNode->left = r->left ;
    r->left = NewNode;

    
}

// Tree : 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1

int main()
{
    BTreeNode *Root = takeInputL();
    PrintTL(Root);

    //CreateD(Root);

    // BST r1;

    // r1.root = Root;

    // r1.InsertE(Root, 10);

    //r1.DeleteN(Root, 5);

    // PrintPath(Root,2);

    // int arr[] = {1, 2, 3, 4, 5, 6, 7};

    // int n = sizeof(arr) / sizeof(int);

    // BSTtoLL(Root);

    // v.push_back(NULL);

    cout << "\nAfter performing the opertaion" << endl<< endl;

    // auto it = v.begin();

    // for (int i = 0; i < v.size() - 1; i++)
    // {
    //     v[i]->next = v[i + 1];

    //     if (v[i] != NULL)
    //     {
    //         cout << v[i]->data << " ";
    //     }
    // }

    PrintTL(Root);

    return 0;
}

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
    public :

    int data ;
    int* next ;

};

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

int maxx(int a, int b)
{
    return (a > b ? a : b);
}

int minn(int a, int b)
{
    return (a > b ? b : a);
}

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

int NumNodes(BTreeNode *r)
{
    if (r == NULL)
    {
        return 0;
    }

    return 1 + NumNodes(r->left) + NumNodes(r->right);
}

bool IsPresentX(BTreeNode *r, int x)
{
    if (r == NULL)
    {
        return false;
    }

    if (r->data == x)
    {
        return true;
    }

    return IsPresentX(r->left, x) || IsPresentX(r->right, x);
}

int Height(BTreeNode *r)
{
    if (r == NULL)
    {
        return 0;
    }

    return 1 + maxx(Height(r->left), Height(r->right));
}

void Mirror(BTreeNode *r)
{
    if (r == NULL)
    {
        return;
    }

    BTreeNode *t = r->left;

    r->left = r->right;

    r->right = t;

    Mirror(r->left);

    Mirror(r->right);
}

void PreOrderBTree(BTreeNode *r)
{

    if (r == NULL)
    {
        return;
    }

    cout << r->data << " ";

    PreOrderBTree(r->left);
    PreOrderBTree(r->right);
}

void PostOrderBTree(BTreeNode *r)
{

    if (r == NULL)
    {
        return;
    }

    PostOrderBTree(r->left);
    PostOrderBTree(r->right);
    cout << r->data << " ";
}

// BTreeNode *TreeFInPre(int a[], int b[], int rootpIndex, int rootiIndex, int lis, int lie, int lps, int lpe, int ris, int rie, int rps, int rpe)
// {

//     int d = b[rootpIndex], newrootiIndex;

//     for (int i = 0; i < rootiIndex; i++)
//     {
//         if (a[i] == d)
//         {
//             newrootiIndex = i;
//         }
//     }

//     lie = newrootiIndex - 1;
//     lps = lps + 1;
//     lpe = lps = newrootiIndex - lis;

//     BTreeNode *root = new BTreeNode(d);

//     // root->left = TreeFInPre(a,b);
// }

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

    p3.first = minn(r->data, minn(p1.first, p2.first));

    return p3;
}

int SumN(BTreeNode *r)
{
    if (r == NULL)
    {
        return 0;
    }

    return r->data + SumN(r->left) + SumN(r->right);
}

pair<int, bool> IsBalanced(BTreeNode *r)
{
    if (r == NULL)
    {
        pair<int, bool> p;

        p.first = 0;
        p.second = true;

        return p;
    }

    pair<int, bool> p1 = IsBalanced(r->left);
    pair<int, bool> p2 = IsBalanced(r->right);

    pair<int, bool> p3;

    p3.first = 1 + max(p1.first, p2.first);

    p3.second = (p1.first == p2.first) && (IsBalanced(r->left).second) && (IsBalanced(r->right).second);

    return p3;
}

bool IsLeaf(BTreeNode *r)
{
    if (r->left == NULL && r->right == NULL)
    {
        return true;
    }

    return false;
}

BTreeNode *DeleTL(BTreeNode *r)
{

    if (r == NULL)
    {
        return NULL;
    }

    if (r->left == NULL && r->right == NULL)
    {
        free(r);
        return NULL;
    }

    r->left = DeleTL(r->left);
    r->right = DeleTL(r->right);

    return r;
}

BTreeNode* TreeLev()
{
    int rootd;

    //cout << "Enter root data" << endl;
    cin >> rootd;

    BTreeNode *root = new BTreeNode(rootd);
    queue<BTreeNode *> pendingnodes;
    //queue<int> linknodes;
    pendingnodes.push(root);
    pendingnodes.push(NULL);
    //linknodes.push(rootd);

    while (pendingnodes.size() != 0)
    {

        BTreeNode *t = pendingnodes.front();
        pendingnodes.pop();

        if (t!=NULL)
        {
            cout << t->data <<" ";
            int leftd;
            cin >> leftd;
            if (leftd != -1)
            {

                BTreeNode *left = new BTreeNode(leftd);
                

                pendingnodes.push(left);
                //linknodes.push(leftd);
            }

            if (leftd == -1)
            {
                t->left =NULL ;
            
            }

            //cout << "Enter the right child of " << t->data << endl;
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

        if (t==NULL&&pendingnodes.size()!=0)
        {
                cout<<endl;
              pendingnodes.push(NULL);  
        }

       
        
        

    }

    return root ;

}

// Tree : 1 2 3 4 5 -1 10 -1 -1 -1 -1 -1 -1

int main()
{

    BTreeNode *Root = TreeLev();

    // PrintTL(Root);

    cout << endl;

    // Mirror(Root);

    //PrintTL(Root);
   // BTreeNode* root = DeleTL(Root);
    cout << endl;

    //PrintTL(root);


    // PostOrderBTree(Root);
    //  cout<<"Is 10 Present : "<<IsPresentX(Root,10)<<endl;

    // cout<<NumNodes(Root);

    // cout<<"Height is "<<Height(Root)<<endl;

    // cout << "The minimum is " << minMax(Root).first << " and the maximum is " << minMax(Root).second << endl;
    // cout<<SumN(Root);
    // cout << "The height of the tree is  :" << IsBalanced(Root).first << endl;
    // cout << "Is the tree balanced   :" << IsBalanced(Root).second << endl;
    delete Root;

    return 0;
}
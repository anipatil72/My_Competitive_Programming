#include <iostream>
#include <vector>
#include <queue>
#include <bits/stdc++.h>
using namespace std;

int sum;
bool b = 0;

vector<int> v1;

deque<int> q;

vector<deque<int>> v;

class LBST
{
public:
    int h;

    bool isBST;
    int LargestBST;
};

class TreeNode
{
public:
    int data;
    TreeNode *next;

    TreeNode(int d)
    {
        this->data = d;
    }
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

vector<TreeNode *> treetoLL()
{

    int rootd;

    vector<TreeNode *> v;

    cin >> rootd;

    TreeNode *root = new TreeNode(rootd);
    // root->next = NULL;
    v.push_back(root);
    queue<TreeNode *> pendingnodes;
    // queue<int> linknodes;
    pendingnodes.push(root);
    pendingnodes.push(NULL);

    TreeNode *head = root;
    TreeNode *tail = root;

    // linknodes.push(rootd);

    while (pendingnodes.size() != 0)
    {

        TreeNode *t = pendingnodes.front();
        pendingnodes.pop();

        if (t != NULL)
        {

            tail->next = t;
            tail = t;
            int leftd;
            cin >> leftd;
            if (leftd != -1)
            {

                TreeNode *left = new TreeNode(leftd);

                pendingnodes.push(left);

                // linknodes.push(leftd);
            }

            if (leftd == -1)
            {
            }
            // if (pendingnodes.front()==NULL)
            // {
            //     tail->next = pendingnodes.front() ;
            //     b = 1;

            // }

            int rightd;
            cin >> rightd;
            if (rightd != -1)
            {

                TreeNode *right = new TreeNode(rightd);

                pendingnodes.push(right);
            }

            if (rightd == -1)
            {
            }
        }

        if (t == NULL && pendingnodes.size() != 0)
        {
            tail->next = NULL;

            // cout<<endl;

            head = pendingnodes.front();
            v.push_back(head);
            tail = pendingnodes.front();
            pendingnodes.push(NULL);
        }

        if (t == NULL && pendingnodes.size() == 0)
        {
            tail->next = NULL;
            break;
        }
    }

    return v;
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

void PrintNoSib(BTreeNode *r)
{

    if (r == NULL)
    {
        return;
    }

    if (r->left == NULL && r->right == NULL)
    {
        return;
    }

    if (r->left == NULL && r->right != NULL)
    {
        cout << r->right->data << " ";
    }

    if (r->left != NULL && r->right == NULL)
    {
        cout << r->left->data << " ";
    }

    PrintNoSib(r->left);
    PrintNoSib(r->right);
}

BTreeNode *BinarySearch(BTreeNode *r, int s)
{

    if (r == NULL)
    {
        return NULL;
    }

    if (r->data == s)
    {
        return r;
    }

    BTreeNode *a;

    if (r->data < s)
    {
        a = BinarySearch(r->right, s);
    }

    if (r->data > s)
    {
        a = BinarySearch(r->left, s);
    }

    return a;
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

void PrintInRange(BTreeNode *r, int m, int M)
{

    if (r == NULL)
    {
        return;
    }

    if (r->data >= M)
    {
        if (r->data == M)
        {
            cout << r->data << " ";
        }

        PrintInRange(r->left, m, M);
        return;
    }

    if (r->data <= m)
    {
        if (r->data == m)
        {
            cout << r->data << " ";
        }
        PrintInRange(r->right, m, M);
        return;
    }

    if (r->data <= M && r->data >= m)
    {
        PrintInRange(r->left, m, M);
        cout << r->data << " ";
        PrintInRange(r->right, m, M);
    }
}

void isLCA(BTreeNode *r, int a, int b)
{

    if (r == NULL)
    {
        return;
    }

    if (IsPresentX(r->right, a) && IsPresentX(r->right, b))
    {
        isLCA(r->right, a, b);
        return;
    }

    if (IsPresentX(r->left, a) && IsPresentX(r->left, b))
    {
        isLCA(r->left, a, b);
        return;
    }

    if (IsPresentX(r->right, a) && IsPresentX(r->left, b))
    {
        cout << r->data << endl;
        return;
    }

    if (IsPresentX(r->left, a) && IsPresentX(r->right, b))
    {
        cout << r->data << endl;
        return;
    }

    if (r->data == a && (IsPresentX(r->left, b) || IsPresentX(r->right, b)))
    {
        cout << r->data << endl;
        return;
    }

    if (r->data == b && (IsPresentX(r->left, a) || IsPresentX(r->right, a)))
    {
        cout << r->data << endl;
        return;
    }

    else
    {
        cout << "-1" << endl;
    }
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

LBST LargestBST(BTreeNode *r)
{
    if (r == NULL)
    {
        LBST b;

        b.h = IsBalanced(r).first;
        b.isBST = IsBalanced(r).second;
        b.LargestBST = 0;
    }

    LBST left = LargestBST(r->left);
    LBST right = LargestBST(r->right);

    LBST cur;
    cur.h = IsBalanced(r).first;
    cur.isBST = left.isBST && right.isBST;

    if (IsBalanced(r).second)
    {
        cur.LargestBST = IsBalanced(r).first;
    }
    else
    {
        cur.LargestBST = max(left.LargestBST, right.LargestBST);
    }

    return cur;
}

void RePlacewithH(BTreeNode *r)
{

    if (r == NULL)
    {
        return;
    }

    RePlacewithH(r->right);
    sum = sum + r->data;
    r->data = sum;
    RePlacewithH(r->left);
}

bool IsLeaf(BTreeNode *r)
{
    if (r->left == NULL && r->right == NULL)
    {
        return true;
    }

    return false;
}

void PathSum(BTreeNode *r, int k)
{
    if (r == NULL)
    {
        return;
    }

    sum = sum + r->data;
    q.push_back(r->data);

    PathSum(r->left, k);
    PathSum(r->right, k);

    if (IsLeaf(r) && sum == k)
    {
        v.push_back(q);
    }

    sum = sum - r->data;
    q.pop_back();
}

void PrintD(BTreeNode *r, int k)
{

    sum++;
    if (sum == k)
    {
        cout << r->data << endl;
    }

    PrintD(r->left, k);
    sum--;

    sum++;
    if (sum == k)
    {
        cout << r->data << endl;
    }

    PrintD(r->right, k);
    sum--;
}

void Push(BTreeNode *r)
{
    if (r == NULL)
    {
        return;
    }

    v1.push_back(r->data);
    Push(r->left);
    Push(r->right);
}

bool BSearch(BTreeNode *r, int k)
{

    if (r == NULL)
    {
        return false ;
    }

    if (r->data == k)
    {
        return true;
    }

    bool b1, b2;

    if (r->data < k)
    {
        b1 = BSearch(r->right, k);
        return b1 ;
    }
    if (r->data > k)
    {
        b2 = BSearch(r->left, k);
        return b2 ;
    }

    return b1 || b2;
}

void PairSum(BTreeNode *r,int s)
{
    v1.push_back(r->data);

    Push(r->left);

    for (int i = 0; i < v1.size(); i++)
    {
            if (BSearch(r,s - v1[i])&&(s-v1[i])>v1[i])
            {
                cout<<v1[i]<<" "<<s -v1[i]<<endl;    
            }
            
    }
    
}

void EqualDist(BTreeNode *r, int n, int k)
{
    if (r == NULL)
    {
        return;
    }

    if (r->data == n)
    {
        b = 1;

        sum = 0;
        PrintD(r->left, k);
        PrintD(r->right, k);
        // EqualDist(r->left,n, k);
        // sum = 0;
        // EqualDist(r->right,n, k);
        // sum = 0;
    }

    EqualDist(r->left, n, k);
    EqualDist(r->right, n, k);
}

// Tree = 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1

int main()
{

    time_t start, end;

    time(&start);

    BTreeNode *Root = takeInputL();

    PairSum(Root,12);

    // EqualDist(Root, 3, 1);

    // PathSum(Root, 13);

    // for (int i = 0; i < v.size(); i++)
    // {
    //     while (v[i].size() != 0)
    //     {
    //         int d = v[i].front();

    //         cout << d << " ";

    //         v[i].pop_front();
    //     }

    //     cout << endl;
    //  }

    // cout << "Before Operating\n";

    // PrintTL(Root);

    // RePlacewithH(Root);

    // cout << "After Operating\n";
    // PrintTL(Root);

    // isLCA(Root, 2, 6);

    // int ans = LargestBST(Root).LargestBST;

    // cout<<ans<<endl;;

    // vector<TreeNode *> v1;

    // v1 = treetoLL();

    // for (int i = 0; i < v1.size(); i++)
    // {
    //     vector<int> v2;
    //     TreeNode *temp = v1[i];

    //     while (temp != NULL)
    //     {
    //         v2.push_back(temp->data);
    //         // cout << temp->data << " ";
    //         temp = temp->next;
    //     }

    //     if (i % 2 == 1)
    //     {

    //         for (int j = v2.size() - 1; j >= 0; j--)
    //         {
    //             cout << v2[j] << " ";
    //         }

    //         cout << endl;
    //     }

    //     if (i % 2 == 0)
    //     {
    //         for (int j = 0; j < v2.size(); j++)
    //         {
    //             cout << v2[j] << " ";
    //         }
    //cout << endl;
    //     }
    // }

    // PrintNoSib(Root);

    // if (BinarySearch(Root,2)!=NULL)
    // {
    //        cout<<"true"<<endl;
    //         cout<<BinarySearch(Root,2)->data<<endl;
    // }

    // if (BinarySearch(Root,2)==NULL)
    // {
    //        cout<<"false"<<endl;
    // }

    // PrintInRange(Root, 5, 10);

    // unsync the I/O of C and C++.
    ios_base::sync_with_stdio(false);

    // fun();

    // Recording end time.
    time(&end);

    // Calculating total time taken by the program.
    double time_taken = double(end - start);
    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;

    return 0;
}
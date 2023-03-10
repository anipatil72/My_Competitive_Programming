#include <iostream>
#include <queue>
#include <vector>
#include <bits/stdc++.h>
//#include <algorithm>

using namespace std;

class treenode
{

public:
    int data;
    vector<treenode *> children;

    treenode(int d)
    {
        data = d;
    }
};

int g  = 1;
int t  ;
int m ;

treenode* p ;

int maxx(int a, int b)
{
    return (a > b ? a : b);
}

int minn(int a, int b)
{
    return (a < b ? a : b);
}

treenode *takeInputL()
{

    int rootdata;
    queue<treenode *> q;

    cout << "Enter data : " << endl;

    cin >> rootdata;

    treenode *root = new treenode(rootdata);
    q.push(root);

    while (q.size() != 0)
    {
        treenode *t = q.front();

        q.pop();

        cout << "enter the number of children of " << t->data << endl;
        int childNum;

        cin >> childNum;

        for (int i = 0; i < childNum; i++)
        {
            cout << "enter the " << i << "th child of " << t->data << endl;
            int e;
            cin >> e;

            treenode *child = new treenode(e);

            t->children.push_back(child);
            q.push(child);
        }
    }

    return root;
}

treenode *takeInputR()
{
    int rootdata;

    cout << "Enter root  data : " << endl;

    cin >> rootdata;

    treenode *root = new treenode(rootdata);

    cout << "Enter the number of Children of this node" << endl;
    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        treenode *child = takeInputR();
        root->children.push_back(child);
    }

    return root;
}

void printT(treenode *r)
{
    cout << r->data << " :";

    for (int i = 0; i < r->children.size(); i++)
    {

        cout << r->children[i]->data << ",";
    }

    cout << endl;

    for (int i = 0; i < r->children.size(); i++)
    {
        printT(r->children[i]);
    }
}

int Sum(treenode *r)
{

    int sum = r->data;

    for (int i = 0; i < r->children.size(); i++)
    {
        sum = sum + Sum(r->children[i]);
    }

    return sum;
}

int LargestData(treenode *r)
{

    int l = r->data;

    for (int i = 0; i < r->children.size(); i++)
    {

        if (LargestData(r->children[i]) > l)
        {
            l = LargestData(r->children[i]);
        }
    }

    return l;
}

int Height(treenode *r)
{
    int h = 1;

    for (int i = 0; i < r->children.size(); i++)
    {
        if (Height(r->children[i]) > h)
        {
            h = Height(r->children[i]);
        }
    }

    return h + 1;
}

int LeafNum(treenode *r)
{
    if (r->children.size() == 0)
    {
        return 1;
    }
    int a = 0;

    for (int i = 0; i < r->children.size(); i++)
    {
        a = a + LeafNum(r->children[i]);
    }

    return a;
}

void PreOrderTraversal(treenode *r)
{
    cout << r->data << " ";

    for (int i = 0; i < r->children.size(); i++)
    {
        PreOrderTraversal(r->children[i]);
    }
}

void PostOrderTraversal(treenode *r)
{

    for (int i = 0; i < r->children.size(); i++)
    {
        PostOrderTraversal(r->children[i]);
    }

    cout << r->data << " ";
}

void Destructor(treenode *r)
{
    for (int i = 0; i < r->children.size(); i++)
    {
        Destructor(r->children[i]);
    }

    delete r;
}

int ContainsX(treenode *r, int x)
{
    if (r->data == x)
    {
        return 1;
    }

    int ans = false;

    for (int i = 0; i < r->children.size(); i++)
    {
        ans = ContainsX(r->children[i], x);

        if (ans == 1)
        {
            break;
        }
    }

    return ans;
}

int MaxDSum(treenode *r)
{

    int sum = r->data;

    // treenode* d ;

    for (int i = 0; i < r->children.size(); i++)
    {
        sum = sum + r->children[i]->data;
    }

    for (int i = 0; i < r->children.size(); i++)
    {

        if (MaxDSum(r->children[i]) < sum)
        {
            m = sum;
            p = r;
        }
    }

    return m;
}

int NextL(treenode *r, int n)
{

    int m;
    int m1;
    int q = (r->data > n ? r->data : -1);

    for (int i = 0; i < r->children.size(); i++)
    {

        m1 = NextL(r->children[i], n);

        // m = minn(NextL(r->children[i],n),m);
        if (g == 1)
        {
            if (m1 != -1 && q != -1)
            {
                m = minn(m1, q);
            }

            if (m1 == -1 && q != -1)
            {
                m = q;
            }

            if (m1 != -1 && q == -1)
            {
                m = m1;
            }

            if (m1 == -1 && q == -1)
            {
               continue; 
            }
            
            g = 0;
            continue;
        }

        if (m1 < m && m1 != -1)
        {
            m = m1;
        }
    }

    if (r->children.size() == 0)
    {
        return q;
    }

    return m;
}

void SecondLargest(treenode *r,int m)
{

    for (int i = 0; i < r->children.size(); i++)
    {
        SecondLargest(r->children[i],m);
    }

        if (r->data > t && r->data!= m )
        {
            t = r->data ;
        }
        
}

void JustL(treenode *r,int n)
{

    for (int i = 0; i < r->children.size(); i++)
    {
        JustL(r->children[i],n);
    }

        if ( r->data > n && g ==1 )
        {
            t = r->data ;
           // cout<<"I am here !"<<endl;
            g = 0 ;
        }

        if (r->data <t && r->data > n)
        {
                t = r->data ;
        }
        
        
}

treenode *takeInputLD()
{

    int rootdata;
    queue<treenode *> q;

    cout << "Enter data : " << endl;

    cin >> rootdata;

    int j = 0;

    treenode *root = new treenode(j);
    q.push(root);

    while (q.size() != 0)
    {
        treenode *t = q.front();

        q.pop();

        cout << "enter the number of children of " << t->data << endl;
        int childNum;

        cin >> childNum;

        for (int i = 0; i < childNum; i++)
        {
            cout << "enter the " << i << "th child of " << t->data << endl;
            int e;
            cin >> e;

            treenode *child = new treenode(j);

            t->children.push_back(child);
            q.push(child);
        }

        j++ ;
    }

    return root;
}

int main()
{

    treenode *Root = takeInputL();

    // printT(Root);

    // Destructor(Root);

    // printT(Root);

    // int actual_size = Height(Root) - 1;
    // cout << LeafNum(Root)<<endl;

    // PostOrderTraversal(Root);

    // cout<<ContainsX(Root,40);

    // cout<<p->data<<endl;
    // cout<<MaxDSum(Root)<<endl;
     
    //cout <<NextL(Root, 3)<< endl;

    //int maxi = LargestData(Root);

    //  SecondLargest(Root,maxi);

    // JustL(Root,3);

    // cout<<t<<endl;

    //printT(Root);

    

    return 0;
}
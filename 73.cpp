#include <bits/stdc++.h>
using namespace std;

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

TreeNode *Sort(TreeNode *h)
{
    if (h == NULL)
    {
        return NULL;
    }

    h->next = Sort(h->next);

    if (h->data > h->next->data)
    {
        TreeNode *t = h->next;
        TreeNode *temp = h->next;
        while (t->data < h->data && t->next != NULL)
        {
            t = t->next;
        }

        h->next = t->next;
        t->next = h;

        return temp;
    }

    return h;
}

int main()
{

    return 0;
}
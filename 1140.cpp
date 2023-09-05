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
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node *copyRandomList(Node *head)
{

    if (head == NULL)
    {
        return NULL;
    }

    unordered_map<Node *, Node *> org;
    // unordered_map<Node*,Node*> org;

    Node *tem = head;

    Node *prev = NULL;

    while (tem != NULL)
    {

        Node *des = new Node(tem->val);

        org[tem] = des;

        if (prev != NULL)
        {
            prev->next = des;
        }

        prev = des;

        tem = tem->next;
    }

    prev->next = NULL;

    tem = head;

    while (tem != NULL)
    {

        if (tem->random != NULL)
        {
            // tem->random = org[tem->random];

            Node *desk = org[tem];

            desk->random = org[tem->random];
        }
        else
        {
            Node *desk = org[tem];

            desk->random = NULL;
        }

        tem = tem->next;
    }

    return org[head];
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
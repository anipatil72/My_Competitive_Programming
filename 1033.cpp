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

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

struct Node *makeUnion(struct Node *head1, struct Node *head2)
{
    set<int> s;

    while (head1 != NULL)
    {
        s.insert(head1->data);

        head1 = head1->next;
    }

    while (head2 != NULL)
    {
        s.insert(head2->data);

        head2 = head2->next;
    }

    auto it = s.begin();

    Node *head = NULL;
    Node *cur = NULL;

    while (it != s.end())
    {
        Node *tem = new Node(*it);
        if (head == NULL)
        {
            head = tem;

            cur = tem;
        }
        else
        {
            cur->next = tem;

            cur = tem;
        }

        it++;
    }

    if (cur != NULL)
    {
        cur->next = NULL;
    }

    return head;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
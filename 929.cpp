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

Node *reverseLinkedList(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    if (head->next == NULL)
    {
        return head;
    }

    Node *cur = head;

    Node *prev = NULL;

    while (cur != NULL)
    {
        Node *tem = cur->next;

        cur->next = prev;

        prev = cur;

        cur = tem;
    }

    return prev;
}

int getNthFromLast(Node *head, int n)
{
    if (head == NULL)
    {
        return -1;
    }

    if (head->next == NULL)
    {
        return head->data;
    }

    Node *des = reverseLinkedList(head);

    int count = 0;

    Node *tem = des;

    int ans = 0;

    while (tem != NULL)
    {
        count++;

        if (count == n)
        {
            // return tem->data;

            ans = tem->data;
        }

        tem = tem->next;
    }

    Node *fin = reverseLinkedList(des);

    return ans;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
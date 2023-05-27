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

struct Node *modifyTheList(struct Node *head)
{
    Node *slow = head;

    int count = 0;

    Node *der = head;

    while (der != NULL)
    {
        der = der->next;

        count++;
    }

    // cout << "Here is the count : " << count << endl;

    if (slow == NULL)
    {
        return NULL;
    }

    if (head->next == NULL)
    {
        return head;
    }

    Node *fast = head;

    while (fast != NULL)
    {
        Node *des = fast->next;

        if (des == NULL)
        {
            break;
        }

        if (des->next == NULL)
        {
            break;
        }

        slow = slow->next;

        fast = fast->next->next;
    }

    der = head;

    while (der != NULL)
    {
        if (der->next == slow)
        {
            break;
        }

        der = der->next;
    }

    // slow = slow->next;

    // cout << "This is der : " << der->data << endl;
    // cout << "This is slow : " << slow->data << endl;

    Node *desk = (count & 1 ? der : slow);

    Node *nexx = slow->next;

    desk->next = NULL;

    Node *foc = reverseLinkedList(head);

    Node *dexx = foc;

    Node *tex = nexx;

    while (tex != NULL && dexx != NULL)
    {
        int tt = dexx->data;

        int dd = tex->data;

        tex->data = tt;

        dexx->data = dd - tt;

        tex = tex->next;

        dexx = dexx->next;
    }

    Node *fin = reverseLinkedList(foc);

    desk->next = (count & 1 ? slow : nexx);

    return fin;
}

int main()
{

    Node *fir1 = new Node(10);
    Node *fir2 = new Node(4);
    Node *fir3 = new Node(5);
    Node *fir4 = new Node(3);
    Node *fir5 = new Node(6);

    fir1->next = fir2;

    fir2->next = fir3;

    fir3->next = fir4;

    fir4->next = NULL;

    fir5->next = NULL;

    Node *ans = modifyTheList(fir1);

    while (ans != NULL)
    {
        cout << ans->data << " ";

        ans = ans->next;
    }

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
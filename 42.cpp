#include <iostream>
#include <stack>

using namespace std;

class ListNode
{

public:
    int val;
    ListNode *next;

    ListNode(int a)
    {
        this->val = a;
        this->next = NULL;
    }
};

class Pair
{

public:
    ListNode *Head;
    ListNode *Tail;
};

ListNode *RevLLI(ListNode *h)
{

    ListNode *t = h;
    ListNode *h1;
    ListNode *h2;
    ListNode *h3;

    h1 = h->next;
    // cout<<h1->val<<endl;

    while (h1 != NULL)
    {

        h2 = t;

        t = h1;

        h1 = t->next;

        t->next = h2;
        // cout<<t->val<<endl;
        // t= h3 ;
    }

    t->next = h2;

    h->next = NULL;

    return t;
}

Pair RevLLR(ListNode *h)
{
    // ListNode *last;

    if (h == NULL || h->next == NULL)

    {

        Pair ans;

        ans.Head = h;
        ans.Tail = h;

        return ans;
    }

    Pair small = RevLLR(h->next);

    Pair ans;
    small.Tail->next = h;
    h->next = NULL;

    ans.Head = small.Head;
    ans.Tail = h;

    return ans;
}

ListNode *RetH(Pair p)
{
    return p.Head;
}

ListNode *Merge(ListNode *h1, ListNode *h2)
{

    if (h1 == NULL)
    {
        return h2;
    }

    if (h2 == NULL)
    {
        return h1;
    }

    ListNode *fH;
    ListNode *fT;
    ListNode *t;

    int c = 0;

    fH = (h1->val < h2->val) ? (h1) : (h2);

    fT = fH;

    while (h1 != NULL && h2 != NULL)
    {

        if (fT == h1)
        {
            h1 = h1->next;

            if (h1 == NULL)
            {
                fT->next = h2;
                break;
            }

            t = (h1->val < h2->val) ? (h1) : (h2);
            fT->next = t;
            fT = t;
        }
        else if (fT == h2)
        {

            h2 = h2->next;

            if (h2 == NULL)
            {
                fT->next = h1;
                break;
            }

            t = (h1->val < h2->val) ? (h1) : (h2);
            fT->next = t;
            fT = t;
        }
    }

    return fH;
}

ListNode *Mid(ListNode *h)
{
    ListNode *slow = h;
    ListNode *fast = h;

    fast = h->next;

    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;

        fast = fast->next->next;
    }

    if (fast->next != NULL && fast->next->next == NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

ListNode *LinListInput()
{

    ListNode *h = NULL;
    ListNode *tail;

    int a;

    cin >> a;
    while (a != -1)
    {
        ListNode *NewListNode = new ListNode(a);

        if (h == NULL)
        {

            h = NewListNode;
            tail = NewListNode;
        }

        else
        {
            tail->next = NewListNode;
            tail = tail->next;
        }

        cin >> a;
    }
    return h;
}

void PrinLL(ListNode *head)
{

    ListNode *h = head;
    while (h != NULL)
    {
        cout << h->val << " ";
        // cout<<" I am here!"<<endl;

        h = h->next;
    }
}

ListNode *reverseBetween(ListNode *head, int left, int right)
{

    stack<int> s;

    ListNode *t = head;

    int count = 0;

    while (count < left - 1)
    {

        // cout<<"Before left : "<<t->val<<"\n";
        t = t->next;
        count++;
    }

    while (count <= right - 1)
    {
        // cout<<"Before right : "<<t->val<<"\n";
        s.push(t->val);
        t = t->next;
        count++;
    }

    t = head;

    count = 0;

    while (count < left - 1)
    {
        t = t->next;
        count++;
    }

    while (count <= right - 1)
    {
        int d = s.top();

        s.pop();

        t->val = d;

        t = t->next;

        count++;
    }

    return head;
}

ListNode *removeDuplicates(ListNode *h)
{
    ListNode *t = h;

    ListNode *prev = h;

    if (t->next == NULL)
    {
        return h;
    }

    t = t->next;

    while (t->next != NULL)
    {
        if (t->val == prev->val)
        {
            t = t->next;
            continue;
        }

        prev->next = t;
        prev = t;
        t = t->next;
    }

    if (prev->val == t->val)
    {
        prev->next = NULL;
    }
    else
    {
        prev->next = t;
    }

    return h;
}

ListNode *removeNthNodefromEnd(ListNode *h, int n)
{
    ListNode *t = h;

    int count = 0;

    while (t != NULL)
    {

        count++;

        t = t->next;
    }

    if (n > count)
    {
        h = h->next;

        delete t;
        return h;
    }

    t = h;

    for (int i = 0; i < count - n - 1; i++)
    {
        t = t->next;
    }

    if ((count - n) == 0)
    {
        ListNode *d = h;

        h = t->next;

        delete d;
    }
    else
    {
        ListNode *d = t->next;
        ListNode *p = t->next->next;

        t->next = p;

        delete d;
    }

    return h;
}

ListNode *rotateList(ListNode *h, int n)
{

    ListNode *t = h;

    ListNode *tail = h;

    if (t->next == NULL)
    {
        return h;
    }

    int count = 0;

    while (t != NULL)
    {
        count++;

        tail = t;

        t = t->next;
    }

    if (n >= count)
    {
        return rotateList(h, n % count);
    }

    t = h;

    for (int i = 0; i < count - n - 1; i++)
    {
        t = t->next;
    }

    ListNode *d = t->next;

    tail->next = h;

    h = d;

    t->next = NULL;

    return h;
}

ListNode *AlternateReverse(ListNode *A, int B)
{

    int n = 0;

    ListNode *t = A;

    if (A->next == NULL || A == NULL)
    {
        return A;
    }

    // while (t!=NULL)
    // {
    //     n++;
    // }

    int count = 0;

    ListNode *head = A;
    ListNode *tail = A;

    while (count != B)
    {

        count++;
        t = t->next;

        if (t->next == NULL)
        {
            break;
        }
    }

    return A;
}

// ListNode *reverseBetween(ListNode *A, int B, int C)
// {

//     ListNode *t;

//     int count = 1;

//     while (count < B - 1)
//     {

//         t = t->next;
//         count++;
//     }

//     ListNode *ft = t;

//     while (count < C + 1)
//     {
//         t = t->next;
//         count++;
//     }

//     return t;
// }

ListNode *swapPairs(ListNode *head)
{

    if (head == NULL)
    {
        return head;
    }

    if (head->next == NULL)
    {
        return head;
    }

    ListNode *slow = head;
    ListNode *fast = head->next;

    while (fast != NULL && slow != NULL)
    {
        int a = slow->val;
        int b = fast->val;

        slow->val = b;
        fast->val = a;

        if (slow->next == NULL)
        {
            break;
        }

        if (fast->next == NULL)
        {
            break;
        }

        slow = slow->next->next;
        fast = fast->next->next;
    }

    return head;
}

ListNode *reverseKGroup(ListNode *head, int k)
{

    if (k == 1)
    {
        return head;
    }

    stack<int> s;

    ListNode *t = head;
    ListNode *slow = head;

    int count = 0;

    while (t != NULL)
    {
        s.push(t->val);
        count++;

        if (count == k)
        {

            while (!s.empty())
            {
                slow->val = s.top();
                s.pop();

                count--;

                slow = slow->next;
            }
        }

        t = t->next;
    }

    return head;
}

bool isPalindrome(ListNode *head)
{

    if (head == NULL || head->next == NULL)
    {
        return true;
    }

    ListNode *mid = Mid(head);

    // cout<<mid->val<<endl;
    // cout<<mid->next->val<<endl;

    ListNode *t = mid->next;

    // while (t->next != mid)
    // {

    //     // cout<<t->val<<" ";
    //     t = t->next;

        
    // }

    // t->next = NULL;

    // cout<<"\n";

  

    mid->next = NULL;



    t = RevLLI(t);

    ListNode *h1 = head;

    ListNode *h2 = t;

    bool flag = true;

    while (h1 != NULL && h2 != NULL)
    {
        if ((h1->val != h2->val))
        {
            flag = false;
            break;
        }

        h1 = h1->next;
        h2 = h2->next;
    }

    // ListNode *j = t;
    // ListNode *k = head;

    // cout<<"The two linked lists are : "<<endl;

    // while (j != NULL)
    // {
    //     cout << j->val << " ";
    //     j = j->next;
    // }

    // cout << "\n";

    // while (k != NULL)
    // {
    //     cout << k->val << " ";
    //     k = k->next;
    // }

    // cout << "\n";

    if (flag && h1 == NULL && h2 == NULL)
    {
        return true;
    }

    return false;
}

int main()
{

    ListNode *head1;
    ListNode *head2;
    ListNode *head3;
    cout << "Enter the first linked list :" << endl;
    head1 = LinListInput();

    // head2 = swapPairs(head1);
    cout<<isPalindrome(head1);

    // head2 = rotateList(head1, 4);

    // head2 = reverseBetween(head1, 1, 8);

    // head2 = RetH(RevLLR(head1));

    // cout << "Enter the second linked list :" << endl;
    // head2 = LinListInput();

    // head3 = Merge(head1, head2);
    // // head2 = RevLLI(head1);

    // cout << "The sorted Linked list is : " << endl;

    //  1 3 6 9 10 14 27 40 59 62 100 201 202 990 -1
    // 2 5 9 10 22 31 52 89 90 101 210 301 489 990 -1

    // 1 2 3 4 5 6 7 8 -1

    // 19  200  239  354  354  375  380  407  442  458  576  587  778  796  797  912 -1
    // 47  79  80  111  126  159  175  175  197  230  257  258  336  401  413  453  507  517  617  627  632  671  695  710  757  766  800  819  832  847  910  938  978 -1

    // PrinLL(head2);

    return 0;
}
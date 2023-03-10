#include <iostream>
#include <stdlib.h>

using namespace std;

struct Node
{
    int data;
    struct Node *ptr;
};

int main()
{

    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));

    struct Node *p = head;
    struct Node *r;
    struct Node *q = head->ptr;

    head->data = 1;
    head->ptr = second;

    second->data = 2;
    second->ptr = third;

    third->data = 0;
    third->ptr = fourth;

    fourth->data = 4;
    fourth->ptr = NULL;

    while (q->data!=0 && q != NULL)
    {

        p = p->ptr;
        q = q->ptr;
    }

        if (q->data == 0)
        {
            p->ptr = q->ptr;
            free(q);
            
        }
    
    
    r = head;

    while (r != NULL)
    {
        printf("Element : %d\n", r->data);
        r = r->ptr;
    }

    return 0;
}
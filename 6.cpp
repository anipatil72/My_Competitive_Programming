#include <iostream>
#include <stdlib.h>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

void LinkedListTraversal(struct Node *head)
{
    struct Node *p = head;

    do 
    {
        printf("Element : %d\n", p->data);
        p = p->next;
    }while(p->next != NULL);

        printf("Element : %d\n", p->data);
    printf("Traversing in the reverse direction\n");

    do
    {
        printf("Elemnet : %d\n", p->data);
        p = p->prev;
    }while (p->prev != NULL);
        printf("Elemnet : %d\n", p->data);
}

int main()
{

    struct Node *N1 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *N2 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *N3 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *N4 = (struct Node *)malloc(sizeof(struct Node));

    N1->next = N2;
    N1->data = 1;
    N1->prev = NULL;

    N2->next = N3;
    N2->data = 2;
    N2->prev = N1;

    N3->next = N4;
    N3->data = 3;
    N3->prev = N2;

    N4->next = NULL;
    N4->data = 4;
    N4->prev = N3;

    LinkedListTraversal(N1);

    return 0;
}
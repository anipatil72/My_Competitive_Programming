#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct st
{
    int size, top;

    int *arr;

} stack;

void push(stack *s, int d)
{
    if (s->top == s->size - 1)
    {
    }

    s->top++;

    s->arr[s->top] = d;
}

int main()
{

    stack s;
    int i, j, k;

    s.size = 9;
    s.top = -1;
    s.arr = (int *)malloc(s.size * sizeof(int));

    push(&s, 9);

    for (i = 0; i < s.top + 1; i++)
    {
        printf("Element : %d\n", s.arr[i]);
    }

    return 0;
}
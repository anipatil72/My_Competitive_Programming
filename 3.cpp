
#include <iostream>

void sswap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

using namespace std;

int main()
{

    int n, i, j, k;
    scanf("%d", &n);

    int a[n];

    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (a[j] > a[j + 1])
            {
                sswap(&a[j], &a[j + 1]);
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}
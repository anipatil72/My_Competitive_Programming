#include <iostream>
using namespace std;

int main()
{

    int n, i, j, k, c;

    scanf("%d", &n);
    scanf("\n");
    int a[n];

    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    for (i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            for (j = i; j < n; j++)
            {
                a[j] = a[j + 1];
            }

            a[n - 1] = 0;
        }
    }

    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}
#include <stdio.h>

int main()
{
    int n, i, j, k, ans;

    scanf("%d", &n);

    int a[n];

    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    for (i = 0; i < n; i++)
    {

        int b = 0;

        for (j = 0; j < i - 1; j++)
        {
            if (a[j] == a[i])
            {
                b = 1;

                ans = a[i];
            }
        }

        for (j = i + 1; j < n; j++)
        {
            if (a[j] == a[i])
            {
                b = 1;
                ans = a[i];
            }
        }
    }

    printf("The repeated Number is %d", ans);

    return 0;
}

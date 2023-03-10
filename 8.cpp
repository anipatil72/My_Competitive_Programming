#include <iostream>
using namespace std;

int main()
{

    int m, n, i, j, k;

    scanf("%d", &m);
    scanf("%d", &n);
    scanf("\n");

    int a[m][n], b[m][n];

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }

        scanf("\n");
    }

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            b[i][j] = a[i][j];
        }
    }

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (a[i][j] == 0)
            {
                for (k = 0; k < m; k++)
                {
                    b[k][j] = 0;
                }

                for (k = 0; k < n; k++)
                {
                    b[i][k] = 0;
                }
            }
        }
    }

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", b[i][j]);
        }

        printf("\n");
    }

    return 0;
}
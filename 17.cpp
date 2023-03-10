#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)

        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

int main()
{

    int t, i, j;

    scanf("%d", &t);

    if (t >= 1 && t <= 10000)
    {
        int n[t];

        int f[t];
        int **c = new int *[t];

        for (i = 0; i < t; i++)
        {

            scanf("%d", &n[i]);

            if (n[i] >= 1 && n[i] <= 200000)
            {

                c[i] = new int[n[i]];

                for (j = 0; j < n[i]; j++)
                {
                    scanf("%d", &c[i][j]);
                }
            }
        }

        // for (i = 0; i < t; i++)
        // {
        //     bubbleSort(c[i], n[i]);
        // }

        //     for (i = 0; i < t; i++)
        // {

        //     for (j = 0; j < n[i]; j++)
        //     {
        //         printf("%d ", c[i][j]);
        //     }

        //     printf("\n");

        // }

        bool b ;

        for (i = 0; i < t; i++)
        {
            for (j = 0; j < n[i] - 2; j++)
            {
                if ((c[i][j] == c[i][j + 1])&&(c[i][j + 1] == c[i][j + 2]))
                {
                   
                    
                        f[i] = c[i][j];
                            //printf("I am here !\n");
                        b = 1;
                        break;
                    
                }
            }

            if (b!= 1 )
            {
               // printf("I am here by !\n");
                // printf(" Before Changing %d\n",f[i]);
                f[i] = -1;
                // printf("After changing %d\n",f[i]);
            }
        }

        for (i = 0; i < t; i++)
        {
            printf("%d\n", f[i]);
        }

        for (i = 0; i < t; i++)
        {
            delete[] c[i];
        }

        delete c;
    }

    return 0;
}
#include <stdio.h>

typedef struct
{

    int roll_number;
    int course_id;

} part;

int main()

{

    part info[1431];

    char dummy;
    int i, j, k, t;

    int distinct_id[21];

    int arr[21][100];

    int count[21];

    for (i = 0; i < 1431; i++)
    {

        scanf("%d", &info[i].roll_number);

        scanf("%c", &dummy);
        scanf("%c", &dummy);
        scanf("%c", &dummy);

        scanf("%d", &info[i].course_id);
    }

    /* for(i=0;i<1431;i++)
     {


     printf("%d ",info[i].roll_number);

     printf("%d\n",info[i].course_id);

     }*/

    int f;
    k = 0;

    for (i = 0; i < 1431; i++)
    {
        f = 0;
        for (j = 0; j < i; j++)
        {

            if (info[i].course_id == info[j].course_id)
            {
                f = 1;
                break;
            }

            else
            {
            }
        }
        if (f == 0)
        {
            distinct_id[k] = info[i].course_id;
            k++;
        }
    }

    for (i = 0; i < 21; i++)
    {

        for (j = 0; j < (21 - (i + 1)); j++)
        {
            if (distinct_id[j] > distinct_id[j + 1])
            {
                t = distinct_id[j];
                distinct_id[j] = distinct_id[j + 1];
                distinct_id[j + 1] = t;
            }
        }
    }

    /*  for(i=0;i<21;i++)
     {

             printf("%d \n",distinct_id[i]);
     }*/

    for (i = 0; i < 21; i++)

    {
        k = 0;

        for (j = 0; j < 1431; j++)
        {
            if (distinct_id[i] == info[j].course_id)
            {
                arr[i][k] = info[j].roll_number;

                k++;
            }
        }
        // printf("%d",k);
        count[i] = k;
    }

    /*for(i=0;i<21;i++)
     {
         printf("%d\n",count[i]);
     }*/

    /*for(i=0;i<21;i++)
    {
        for(j=0;j<count[i];j++)
        {
            printf("%d\n",arr[i][j]);
        }

        printf("\n\n\n");

    }*/

    /*for(i=0;i<21;i++)
      {


              printf("%d\n",count[i]);

      }*/

    int n, m;

    for (i = 0; i < 21; i++)
    {

        for (j = 0; j < count[i]; j++)
        {
            printf("HS%d  %d", distinct_id[i], arr[i][j]);
            n = (arr[i][j]) / 1000;
            m = n % 100;
            // printf("  %d\n",m);
            if (m == 1)
            {
                printf("  CSE\n");
                continue;
            }
            if (m == 2)
            {
                printf("  ECE\n");
                continue;
            }
            if (m == 3)
            {
                printf("   ME\n");
                continue;
            }
            if (m == 4)
            {
                printf("   CE\n");
                continue;
            }
            if (m == 5)
            {
                printf("   DD\n");
                continue;
            }
            if (m == 6)
            {
                printf("   BSBE\n");
                continue;
            }
            if (m == 7)
            {
                printf("   CL\n");
                continue;
            }
            if (m == 8)
            {
                printf("   EEE\n");
                continue;
            }
            if (m == 21)
            {
                printf("   CST\n");
                continue;
            }
            if (m == 22)
            {
                printf("   EP\n");
                continue;
            }
            if (m == 23)
            {
                printf("   M&C\n");
                continue;
            }
        }
    }

    return 0;
}

#include <iostream>
using namespace std;

int maxprofit(int a[])
{

    int max = a[0];

    for (int i = 1; i < 10; i++)
    {
        if (a[i] >= max)
        {
            max = a[i];
        }
    }

    if (max<0)
    {
            return 0;
    }
    

    return max;
}

int main()
{

    int i, j, k = 0;

    int a[6];

    for (i = 0; i < 6; i++)
    {
        scanf("%d", &a[i]);
    }

    int b[10];
    for (i = 0; i < 6; i++)
    {
        for (j = i + 1; j < 6; j++)
        {

            b[k] = a[j] - a[i];
            k++;
        }
    }

    printf("%d", maxprofit(b));

    return 0;
}
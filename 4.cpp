#include <iostream>

using namespace std;

int main()
{
    int n, i, j, k, count = 1;
    scanf("%d", &n);

    int a[n], b[n];

    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    b[0] = a[0];

    for (i = 1; i < n; i++)
    {

        if (a[i] != a[i - 1])
        {
            b[count] = a[i];
            count++;
        }
    }

    for (i = 0; i < count; i++)
    {
        printf("%d ", b[i]);
    }

    return 0;
}
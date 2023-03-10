#include <iostream>
using namespace std;

bool isSorted(int a[], int size)
{
    if (size == 0 || size == 1)
    {
        return true;
    }

    if (a[0] > a[1])
    {
        return false;
    }

    bool isSmallerSorted = isSorted(a + 1, size - 1);

    return isSmallerSorted;
}

int main()
{

    int n, i, j, k;

    scanf("%d", &n);
    scanf("\n");

    int a[n];

    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    if (isSorted(a, n) == 1)
    {

        printf("The Array is Sorted\n");
    }

    if (isSorted(a, n) == 0)
    {

        printf("The Array is not Sorted\n");
    }

    return 0;
}
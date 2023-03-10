#include <iostream>
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

    int t,i,j,k;

    scanf("%d",&t);
    scanf("\n");

    int n[t];

    int a[t][200000];

    for ( i = 0; i < t; i++)
    {
        scanf("%d",&n[i]);

        for ( j = 0; j < n[i]; j++)
        {
            scanf("%d",&a[i][j]);
        }
        
    }





return 0;
}
#include <iostream>
using namespace std;

void insertionSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {

        if (a[i] > a[i + 1])
        {
            swap(a[i], a[i + 1]);

            for (int j = i; j > 0; j--)
            {
                if (a[j] < a[j - 1])
                {
                    swap(a[j - 1], a[j]);
                }
                else
                {
                    break;
                }
            }
        }
    }
}

int main()
{

    int n;
    cin >> n;
    scanf("\n");

    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    insertionSort(a, n);

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}
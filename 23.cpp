#include <iostream>
using namespace std;

void SSort(int a[], int n)
{
    if (n == 1)
    {
        return;
    }
    SSort(a + 1, n - 1);

    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] > a[i + 1])
        {
            swap(a[i], a[i + 1]);
            continue;
        }
        else
        {
            break;
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

    SSort(a, n);

    cout << "After Sorting" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}
#include <iostream>
using namespace std;

int uni(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int c = 0;
        for (int j = 0; j < i; j++)
        {
            if (a[i] == a[j])
            {

                c = 1;
            }
        }

        for (int j = i + 1; j < n; j++)
        {
            if (a[i] == a[j])
            {

                c = 1;
            }
        }
        if (c == 0)
        {
            return a[i];
        }
    }

    return 0;
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

    cout << uni(a, n);

    return 0;
}

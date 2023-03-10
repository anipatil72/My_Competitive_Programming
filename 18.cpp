#include <iostream>
using namespace std;

template <class T>

int search(T a[], int n, T key)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == key)
        {
            return i;
        }
    }

    return -1;
}

int main()
{

    char a[] = {'a', 'b', 'c', 'r', 'h'};
    int n = sizeof(a) / sizeof(char);

    cout << search(a, n, 'r')<<endl;

    return 0;
}
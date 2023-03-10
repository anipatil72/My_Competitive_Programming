#include <iostream>
using namespace std;

// template <class T>

//  class student
// {

//     public :
//     T data ;
//     T * ptr ;

//     student( T d)
//     {
//         data = d ;
//     }

// };

template <class T, int limit>

void Prin(T a[], int n)
{

    if (n > limit)
    {
        return;
    }

    else
    {

        for (int i = 0; i < n; i++)
        {
            cout << a[i] << endl;
        }
    }
}

int main()
{

    const int l = 100;

    char arr[] = {'a', 'i', 'p', '!', 'd'};

    int s = sizeof(arr) / sizeof(char);

    Prin<char , l >(arr, s);

    return 0;
}
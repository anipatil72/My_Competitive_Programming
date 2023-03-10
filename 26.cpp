#include <iostream>
#include <cmath>
using namespace std;

int LCM(int a, int b)
{
    int m;

    if (a > b)
    {
        m = a;
    }

    else
    {
        m = b;
    }

    while (1)
    {
        if (m % a == 0 && m % b == 0)
        {
            break;
        }

        m++;
    }

    return m;
}

int HCF(int a, int b)
{
    int m;

    if (a > b)
    {
        m = b;
    }

    else
    {
        m = a;
    }

    int h = 2;
    int s = 0, j;

    while (h <= m)
    {
        if (a % h == 0 && b % h == 0)
        {
            s = 1;
            j = h;

            break;
        }

        h++;
    }

    if (s == 0)
    {
        return 1;
    }

    return j;
}

int main()
{

    int a, b;

    cout << "Enter the value of a : " << endl;
    cin >> a;

    cout << "Enter the value of b : " << endl;
    cin >> b;

    cout << "The LCM of " << a << " and " << b << " is " << LCM(a, b) << endl;
    cout << "The HCF of " << a << " and " << b << " is " << HCF(a, b) << endl;

    return 0;
}
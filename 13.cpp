#include <iostream>
using namespace std;

long double half_pow(int k)
{
    if (k == 0)
    {
        return 1;
    }

    return half_pow(k - 1) / 2;
}

long double GeoSum(int k)
{
    if (k == 0)
    {
        return 1;
    }

    return GeoSum(k - 1) + half_pow(k);
}

int main()
{

    int n, i, j, k;

    scanf("%d", &n);

    cout << GeoSum(n) << endl;

    return 0;
}
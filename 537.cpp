#include <bits/stdc++.h>
using namespace std;

int numberOfSteps(int n)
{

    int count = 0;

    while (n != 0)
    {
        if (n % 2 == 0)
        {
            n = n / 2;
        }
        else
        {
            n = n - 1;
        }

        count++;
    }

    return count;
}

int main()
{

    return 0;
}
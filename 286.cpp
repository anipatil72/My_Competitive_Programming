#include <bits/stdc++.h>
using namespace std;

int solve(int A)
{

    unsigned int h = (1 << 31);
    unsigned int prod = (1 << 31);

    unsigned int b = 0;

    int i = 0;

    while ((A & h) == 0)
    {
        A = A << 1;
        prod = prod / 2;
        i++;


        // cout<<"I am here!"<<endl;
    }

    // cout<<i<<endl;

    for (int j = i; j < 32; j++)
    {

        if ((A & h) != 0)
        {

            prod = prod / 2;
            A = A << 1;

            continue;
        }

        b += prod;
        prod = prod / 2;
        A = A << 1;
    }

    return b;
}

int main()
{

    cout << solve(5) << endl;

    // unsigned int h = (1<<31);

    // cout<<(5&h)<<endl;

    return 0;
}
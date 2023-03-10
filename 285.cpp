#include <bits/stdc++.h>
using namespace std;

unsigned int Reverse(unsigned int A)
{

    unsigned long int ans = 0;

    unsigned int prod = (1<<31);

    for (int i = 0; i < 32; i++)
    {

        int lastBit = A & 1;

        ans += (prod * lastBit);

        prod = prod / 2;

        A = A >> 1;
    }


    return ans;

}

int main()
{


    cout<<Reverse(3);
    // cout<<pow(2,32);

    return 0;
}
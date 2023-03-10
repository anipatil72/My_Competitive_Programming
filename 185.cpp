#include <bits/stdc++.h>
using namespace std;

long solve(int A, int B)
{

    int temp1 = A;

    int temp2 = B;

    while (temp1 % 7 != 0)
    {
        temp1++;
    }

    while (temp2 % 7 != 0)
    {
        temp2--;
    }

    if (temp1 > temp2)
    {
        return 0;
    }

    if (temp1 == temp2)
    {
        return temp1;
    }

    int n = (temp2 - temp1)/7 + 1;


    // cout<<temp1<<" "<<temp2<<endl;

    // cout<<n<<endl;

    cout<<temp1<<" "<<temp2<<endl;

    long long sum = (long)(n) *( temp1 + temp2)/2;

    //cout<<sum<<endl;

    return sum ;
}

int main()
{
    cout<<solve(99,115)<<endl;

    // cout<<13155%7<<endl;

    return 0;
}
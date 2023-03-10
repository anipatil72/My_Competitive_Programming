#include <bits/stdc++.h>
using namespace std;

int numSetBits(unsigned int A)
{


    int count = 0 ;

    while (A>0)
    {
        A = A&(A-1);
        count++;
    }


    return count ;

    
}


int solve(int A)
{

    int count = 0 ;

    int M = 1000000007;
    for (int i = 1; i < A; i++)
    {
            count+= numSetBits(i);

            count= count%M;
    }


    return count;
    
}

int main()
{

    int n = 11;

    cout<<numSetBits(n)<<endl;

    return 0;
}
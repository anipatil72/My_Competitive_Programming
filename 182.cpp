#include <bits/stdc++.h>
using namespace std;

int GCD(int a,int b)
{

    if (b==0)
    {
            return a ;
    }
    

    return GCD(b,a%b);

}

long solve(int A, int B) {


    long long ans = (long long)A*B/GCD(A,B);

    return ans;
}



int main() 
{

return 0;
}
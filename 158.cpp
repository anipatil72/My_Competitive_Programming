#include <bits/stdc++.h>
using namespace std;

long long factorial(int n)
{

    if (n==0)
    {
            return 1 ;
    }
    
    if (n==1)
    {
            return 1 ;
    }

    long long p = 1;

    for (int i = 1; i <= n; i++)
    {
       p*=i;     
    }


    return p ;
    
    
}



long long printNcR(int n, int r)
{
 
    // p holds the value of n*(n-1)*(n-2)...,
    // k holds the value of r*(r-1)...
    long long p = 1, k = 1;
 
    // C(n, r) == C(n, n-r),
    // choosing the smaller value
    if (n - r < r)
        r = n - r;
 
    if (r != 0) {
        while (r) {
            p *= n;
            k *= r;
 
            // gcd of p, k
            long long m = __gcd(p, k);
 
            // dividing by gcd, to simplify
            // product division by their gcd
            // saves from the overflow
            p /= m;
            k /= m;
 
            n--;
            r--;
        }
 
        // k should be simplified to 1
        // as C(n, r) is a natural number
        // (denominator should be 1 ) .
    }
 
    else
        p = 1;
 
    // if our approach is correct p = ans and k =1
   // cout << p << endl;

   return p ;
}

int uniquePaths(int A, int B) {

    long long a;

    a =  printNcR(A+B -2,A-1);


    return a ;


}

int main() 
{

    cout<<uniquePaths(100,1)<<endl;

    

return 0;
}
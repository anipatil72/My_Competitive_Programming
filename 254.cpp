#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll mulmod(ll a, ll b, ll mod)
{
    ll res = 0; // Initialize result
    a = a % mod;
    while (b > 0)
    {
        // If b is odd, add 'a' to result
        if (b % 2 == 1)
            res = (res + a) % mod;

        // Multiply 'a' with 2
        a = (a * 2) % mod;

        // Divide b by 2
        b /= 2;
    }

    // Return result
    return res % mod;
}

int pow(int x, int n, int d)
{


    if (d==0)
    {
            return 0 ;
    }
    

    if (x==0)
    {
            return 0 ;
    }


    if (x==1)
    {
        return 1;

    }

    if (x==-1)
    {
            if (n%2==0)
            {
                    return  1;
            }


            return d- 1;


            
            
    }
    
    
    

    ll prod = 1;

    for (int i = 0; i < n; i++)
    {


        prod = prod*x;

        prod = prod %d ;
        
        
    }

    return prod;
}

int main()
{

    return 0;
}

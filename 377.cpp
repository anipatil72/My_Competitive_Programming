#include <bits/stdc++.h>
using namespace std;

int GCD(int a, int b)
{
    if (b == 0)
    {
        return a;
    }

    return GCD(b, a % b);
}

int mirrorReflection(int p, int q)
{

    int m = GCD(p,q);

    p = p/m;
    q = q/m;

    if (p%2==1)
    {

        if (q%2==0)
        {
            return 0;
        }
        else
        {
            return 1;
        }
        
        
            
    }
    else
    {
        if (q%2==1)
        {
                return 2;
        }
        
    }


    return -1;
    
    
}

int main()
{

    // cout<<gcvt(10,2);

    return 0;
}
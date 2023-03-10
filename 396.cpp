#include <bits/stdc++.h>
using namespace std;

int divide(int dividend, int divisor)
{

    if (dividend ==0)
    {
            return 0;
    }

    if (abs(divisor)==1)
    {

        if (divisor>0)
        {
            return dividend;
                
        }

        long long x = -dividend;


        return x;
        
    }
    
    

    bool flag1 = true;

    if ((divisor<0&&dividend>0) || (divisor>0&&dividend<0))
    {
       flag1 = false;  

    }

    divisor = abs(divisor);
    dividend = abs(dividend);
    
    

    int count = 0;

    int cur = 0 ;

    while (dividend - cur >= divisor)
    {
        cur+=divisor;
        count++;
    }

    if (!flag1)
    {

        long long l = -count;
        return l;    
    }
    

    return count;
    
}

int main()
{

    cout<<INT_MIN<<endl;
    cout<<INT_MAX<<endl;

    return 0;
}
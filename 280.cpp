#include <bits/stdc++.h>
using namespace std;

int TrailingZeros(int n)
{
    int count = 0 ;

    // cout<<(n&1==0)<<endl;
    while ((n&1)!=1)
    {
        n = n>>1;
        // cout<<n<<endl;
        count++;

    }


    return count ;

    
}

int main() 
{

    int n = 10 ;



    cout<<TrailingZeros(n)<<endl;

return 0;
}
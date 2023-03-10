#include <bits/stdc++.h>
using namespace std;

int solve(int n)
{
    int ans = 0,temp = n;

    int prod = 5 ;

    while (temp>0)
    {
        ans+= temp/5;

        temp = temp/5 ;
        
        
    }
    
    return ans ;

}



int main() 
{

return 0;
}
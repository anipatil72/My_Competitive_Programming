#include <bits/stdc++.h>
using namespace std;


int powerofTWO(int n)
{
    int count = 0 ;


    while (n!=0)
    {
        n = (n&(n-1));
        count++;
    }


    if (count==1)
    {
            return 1;
    }


    return 0 ;
    

}




int main() 
{


    cout<<powerofTWO(1024);


    

return 0;
}
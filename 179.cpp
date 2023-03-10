#include <bits/stdc++.h>
using namespace std;

int solve(int a,int b ,int c)
{

    int count = 0 ;

    bool jump = 1 ;

    if (a==b)
    {
            return a%10==c;
    }
    

    

    while (a<=b)
    {

        while (a%10!=c)
        {
            a++;

            if (a==b)
            {
                    return 0 ;
            }
            
        }
        
        // if (jump)
        // {
        //         if (a%10==c)
        //         {

        //             count ++ ;
        //             jump = 0 ;

        //             a+=10;
        //             continue;
                    
                    
                        
        //         }
        //             a++;
        //             continue;
        // }


        count++;
        a+=10;
        

        
    }

    

    return count ;
    
}



int main() 
{

    cout<<solve(11,111,1)<<endl;

return 0;
}
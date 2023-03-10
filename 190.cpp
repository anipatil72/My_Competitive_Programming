#include <bits/stdc++.h>
using namespace std;

int FirstMissingNumber(int a[],int n)
{

    

    for (int i = 0; i < n; i++)
    {
         if (a[i]!=i)
         {

            int prev = a[i];
                while (prev>=0&&prev<n&&a[prev]!=prev)
                {

                    int temp = a[prev];

                    a[prev] = prev;

                    prev = temp;
                    
                }
                
         }
            
    }


    for (int i = 0; i < n; i++)
    {
            cout<<a[i]<<" ";
    }

    cout<<endl;
    

    int ans ;


    for (int i = 0; i < n; i++)
    {
        if (a[i]!=i)
        {

            return i ;
        }
        
    }
    
    
    return -1 ;
}

int main() 
{

    int a[] = {7,2,4,3,1,0,5,98};

    int s = sizeof(a)/sizeof(int);

    cout<<FirstMissingNumber(a,s);

return 0;
}
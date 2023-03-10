#include <bits/stdc++.h>
using namespace std;

long solve(int A, int B) {


    long term = A ;





    for (int i = 1; i < B; i++)
    {


        if (term%2==0)
        {
                term = term /2 ;
        }
        else
        {
            term = term*3 + 1;
        }
        
        



            
    }
    

return term;
    
}

int main() 
{

    int a = 5 , b = 1 ;


    cout<<solve(a,b);

return 0;
}
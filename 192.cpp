#include <bits/stdc++.h>
using namespace std;

int lengthOfLastWord(const string A) {

    int n = A.size();

    int i = n-1;

    int count = 0 ;

    while (A[i]==' ')
    {

        if (A[i]!=' ')
        {
                break; 
        }
        
        i--;

    }
    

    while (i>=0)
    {
       if (A[i]==' ')
       {
           break; 
       }

       i--;
       count++;
       
    }
    
    

   return count ;
    
}

int main() 
{

    cout<<lengthOfLastWord("Hello World  ");

return 0;
}
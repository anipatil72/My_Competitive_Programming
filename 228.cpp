#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string A)
{
    int n = A.length();

    for (int i = 0; i < n/2; i++)
    {
          if (A[i]!=A[n-i-1])
          {
                return 0 ;
          }
            
    }

    return 1 ;
    
}

int solve(string A) {

    int n = A.size();

    string word = "";

    int count = 0 ;

    for (int i = 0; i < n; i++)
    {

        if (A[i]==' ')
        {

            //cout<<word<<endl;
            if (isPalindrome(word))
            {
                    count++;
            }


            word = "";
            continue;
            
        }

        word += A[i];
        
            
    }

    //cout<<word<<endl;


    if (isPalindrome(word))
    {
        count++;
    }
    
    
return count ;

}

int main() 
{

    string s = "wow mom";

    cout<<solve(s);

return 0;
}
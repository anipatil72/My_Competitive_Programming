#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string &s)
{
    int n = s.length();

    for (int i = 0; i < n / 2; i++)
    {
        if (s[i] != s[n - 1 - i])
        {
            return 0;
        }
    }

    return 1;
}

int Solution::solve(string A)
{
    int n = A.length();

    
    if (n%2==1&&isPalindrome(A))
    {
            return 1;
    }


    string s = A;
    string t = A;

    int i ;

    for ( i = 0; i < n/2; i++)
    {
            if (A[i]!=A[n-1-i])
            {
                 break;   
            }
            
    }

    s.erase(s.begin() + i);

    t.erase(t.end()-1-i);

    if (isPalindrome(s)||isPalindrome(t))
    {
            return 1;
    }
    


    
return 0 ;

}

int main()
{

    string s= "gddg";

    cout<<solve(s);

    return 0;
}
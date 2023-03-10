#include <bits/stdc++.h>
using namespace std;

int isPalindrome(int A) {

    string s = to_string(A);

    int n = s.length();

    for (int i = 0; i < n/2; i++)
    {
        if (s[i]!=s[n-1-i])
        {
             return 0 ;   
        }
        
    }
    
    return 1 ;

}

int main() 
{

    cout<<isPalindrome(12211221);

return 0;
}
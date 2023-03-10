#include <bits/stdc++.h>
using namespace std;

bool isVowel(char c)
{
    if (c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U')
    {
            return true ;
    }

    return false;
    
}


int solve(string A) {

    int count = 0 ;

    int M = 10003;

    int n = A.length();


    for (int i = 0; i < n; i++)
    {
        if (isVowel(A[i]))
        {
            count+= (n-i);

            count = count%M;
        }
        
    }
    



return count ;

}

int main() 
{

    string s = "ABEC";

    cout<<solve(s);

return 0;
}
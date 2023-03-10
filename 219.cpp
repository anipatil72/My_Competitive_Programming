#include <bits/stdc++.h>
using namespace std;

string removeDots(string s)
{
    int n = s.length();

    string ans = "";


    for (int i = 0; i < n; i++)
    {
        if (s[i]!='i')
        {
            ans+= s[i];
        }
        
    }
    

    

    
    
    return ans ;

}

int compareVersion(string A, string B) {

    int i = 0 ;

    A = removeDots(A);
    B = removeDots(B);

    int n = A.length();
    int m = B.length();


    while (i<A.length()&&i<B.length())
    {
        if (A[i] -'0'>B[i] - '0')
        {
            return 1 ;
        }

        if (A[i]-'0'<B[i]-'0')
        {
            return -1;
        }

        if (A[i]-'0'==B[i]-'0')
        {
                i++;
                continue;
        }
        
        
        
    }

    if (i==min(n,m))
    {
        if (min(n,m)==m)
        {
            return 1;
        }

        if (min(n,m)==n)
        {
                return -1;
        }
        
        
    }
    


    return 0 ;


}

int main() 
{

    string v1 = "1.2.31";
    string v2 = "1.21.31";

    cout<<compareVersion()

return 0;
}
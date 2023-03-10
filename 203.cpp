#include <bits/stdc++.h>
using namespace std;

#define ll long long 

ll mulmod(ll a, ll b, ll mod)                 
{
    ll res = 0; // Initialize result
    a = a % mod;
    while (b > 0)
    {
        // If b is odd, add 'a' to result
        if (b % 2 == 1)
            res = (res + a) % mod;
 
        // Multiply 'a' with 2
        a = (a * 2) % mod;
 
        // Divide b by 2
        b /= 2;
    }
 
    // Return result
    return res % mod;
}

bool isVowel(char c)
{
    return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
}

int solve(string A) {

    int M = 1000000007;

    int n = A.length();

    int vcount = 0 ;
    int ccount = 0 ;

    for (int i = 0; i < n; i++)
    {
            if (isVowel(A[i]))
            {
                vcount++;
                vcount = vcount%M;    
            }

            else
            {
                ccount ++;
                ccount = ccount%M;
            }
            
            
    }


    int ans = mulmod(vcount,ccount,M);



    return ans ;

}

int main() 
{

    string s = "abcaiportlu";

return 0;
}
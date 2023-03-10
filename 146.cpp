#include <bits/stdc++.h>
using namespace std;

int gcdExtended(int a, int b, int *x, int *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }
 
    int x1, y1; // To store results of recursive call
    int gcd = gcdExtended(b%a, a, &x1, &y1);
 
    // Update x and y using results of recursive
    // call
    *x = y1 - (b/a) * x1;
    *y = x1;
 
    return gcd;
}

int modInverse(int b, int m)
{
    int x, y; // used in extended GCD algorithm
    int g = gcdExtended(b, m, &x, &y);
 
    // Return -1 if b and m are not co-prime
    if (g != 1)
        return -1;
 
    // m is added to handle negative x
    return (x%m + m) % m;
}
 
// Function to compute a/b under modulo m
int modDivide(int a, int b, int m)
{
    a = a % m;
    int inv = modInverse(b, m);
    
       return (inv * a) % m;
}

vector<int> solve(vector<int> &A) {

    vector<int> v ;

    int n = A.size();

    const int M = 1000000007;

    int p = 1 ;


    for (int i = 0; i < n; i++)
    {

        p = (p*A[i])%M;


            
    }

    for (int i = 0; i < n; i++)
    {
            int d = modDivide(p,A[i],M);

            v.push_back(d);
    }
    
    return v ;


}





int main() 
{

    vector<int> a = {1, 2, 3, 4};

    vector<int>b = solve(a);

    for (int i = 0; i < b.size(); i++)
    {
        cout<<b[i]<<" ";
    }
    

return 0;
}
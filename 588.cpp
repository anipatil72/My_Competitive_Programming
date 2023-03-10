#include <bits/stdc++.h>
using namespace std;

vector<bool>& sieve(int n)
{
    vector<bool> v(n + 1, true);
    for (int i = 2; i * i <= n; i++)
    {
        if (v[i])
        {
            for (int j = i * i; j <= n; j = i + j)
            {
                v[j] = false;
            }
        }
    }
    return v;
}

int countPrimes(int n)
{

    if (n<=2)
    {
           return 0;
            
    }

    if (n==3)
    {
        return 1;
    }
    
    

    vector<bool> ans = sieve(n);

    int count = 0;

    for (int i = 2; i < n; i++)
    {
         if (ans[i])
         {
             count++;   
         }
            
    }

    return count;
    
}

int main()
{

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
    if (n == 1)
    {
        return false;
    }
    if (n == 2 || n == 3)
    {
        return true;
    }
    if (n % 2 == 0 || n % 3 == 0)
    {
        return false;
    }
    for (int i = 5; i * i <= n; i = i + 6)
    {
        if (n % i == 0)
        {
            return false;
        }
        if (n % (i + 2) == 0)
        {
            return false;
        }
    }
    return true;
}

int main() 
{

    int n , m;

    cin>>n>>m;

    int t;

    for (int i = n+1; i < 51; i++)
    {

        if (isPrime(i))
        {
            t = i;
            break; 
        }
        
            
    }


    if (t==m)
    {
            cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    
    
    

return 0;
}
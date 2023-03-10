#include <bits/stdc++.h>
using namespace std;

int sum(int n)
{
    if (n<10)
    {
        return n;
    }

    int s  =  n%10;

    return s + sum(n/10);
    
}

int main() 
{

    cout<<sum(11073);

return 0;
}
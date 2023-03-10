#include <bits/stdc++.h>
using namespace std;

int main() 
{

    int n = 5;

    while (n>0)
    {
        cout<<(n&1);
        n = n>>1;
    }
    

    

return 0;
}
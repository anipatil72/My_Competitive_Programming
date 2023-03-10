#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n, a, b;

    cin >> n >> a >> b;

    if (b==0)
    {
       cout<<"1"<<endl;
       return 0;    
    }
    

    // cout<<n-max(a,n - b) + 1;

    if (a>=n - b)
    {
          cout<<n-a<<endl;  
    }
    else 
    {
        cout<<b+1<<endl;
    }
    
    

    

    return 0;
}
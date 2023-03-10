#include <bits/stdc++.h>
using namespace std;

int solve(int A)
{

    string s = to_string(A);

    int n = s.length();

    int t = A;

    if (n==1)
    {
        return 1;
    }

    long long sum  = 0 ;

    while (t>0)
    {
        int c = t%10;

        sum+= (int)pow(c,n);

        t = t/10;


    }

    // cout<<sum<<endl;

    return A ==sum;
    
    
    
}

int main()
{

    cout<<solve(371);

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int solve(int A)
{

    if (A == 0)
    {
        return 0;
    }

    if (A < 0)
    {
        A = -1 * A;
    }

    int cur = 0 ;
    int i = 1;

    while (cur<A)
    {
        cur += i*(i+1)/2;

        i++;

        if (cur+i>A)
        {
                break ;
        }
        
    }

    int next_cur = cur + i ;


    if ((next_cur-A) - 1 <(A - cur))
    {
        return  i + abs(next_cur-A);    
    }
    
    

    
}

int main()
{

    cout<<solve(42)<<endl;

    return 0;
}
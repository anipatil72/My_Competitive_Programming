#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A) {

    int n = A.size();

    int count = 1 ;

    if (n==1)
    {
            return 1 ;
    }
    

    int m = A[0];

    for (int i = 1; i < n; i++)
    {

       

        if (A[i]>m)
        {
                m = A[i] ;
                count++;
        }
        

        


            
    }
    
    return count;

}

int main() 
{

    vector<int> v = {1, 1, 2, 2};

    cout<<solve(v);

return 0;
}
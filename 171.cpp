#include <bits/stdc++.h>
using namespace std;

int divisibleBy60(vector<int> &A) {

    bool isZero = false;

    bool isEven = false;

    int n = A.size();

    int sum = 0 ;


    for (int i = 0; i < n; i++)
    {

        if (A[i]==0)
        {

            isZero = true;
            continue;
                
        }

        if (A[i]%2==0)
        {
                isEven = true ;
        }
        
        
          sum+= A[i];  
    }

    if (sum==0)
    {
            return 1 ;
    }
    
    
    if (sum%3==0 &&isEven&&isZero)
    {
            return 1 ;
    }
    
    return 0 ;
}

int main() 
{

    vector<int> v ={2, 3};

    cout<<divisibleBy60(v)<<endl;

return 0;
}
#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &A, vector<int> &B) {

    int n = A.size();

    int m = B.size();

    int i = 0 , j = 0 ;

    while (j<m)
    {

        if (A[i]>=B[j])
        {
            A.insert(A.begin() + i,B[j]);

            j++;
        }


        i++;
        
        
    }
    

    
}

int main() 
{

return 0;
}
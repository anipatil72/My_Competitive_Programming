#include <bits/stdc++.h>
using namespace std;

int findMin(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int n = A.size();

    int m = A[0];

    for (int i = 0; i < n; i++)
    {
          m = min(A[i],m);  
    }

    return m;
    
}

int main() 
{

return 0;
}
#include <bits/stdc++.h>
using namespace std;

int repeatedNumber(const vector<int> &A) {

    

    vector<bool> B(A.size() + 1, false); 

    B[A[0]] = true;

    for(int i = 1; i < A.size(); i++){

        if(B[A[i]]){

            return A[i];

        }

        B[A[i]] = true;

    }

    return -1;

}

int main() 
{

return 0;
}
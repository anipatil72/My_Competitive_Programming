#include <bits/stdc++.h>
using namespace std;

int searchInsert(vector<int> &A, int B) {


    auto it = lower_bound(A.begin(),A.end(),B);

    int d = distance(A.begin(),it);


    return d ;
    
}

int main() 
{

    vector<int> v = {1, 3, 5, 6};

    int b = 0 ;

    cout<<searchInsert(v,b);

return 0;
}
#include <bits/stdc++.h>
using namespace std;

vector<int> Si(vector<int>& A, vector<int>& B)
{
    //  vector<int> a = {1,2,7,9,10};
    // vector<int> b = {1,3,10,17,23,45};       

    
    vector<int> c(min(A.size(),B.size()));
    auto it = set_intersection(A.begin(),A.end(),B.begin(),B.end(),c.begin());


    return c;
}

int main()
{

    return 0;
}
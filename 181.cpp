#include <bits/stdc++.h>
using namespace std;

int addNumbers(int A, int B) {
    
    vector<int> v ;

    v.push_back(A);
    v.push_back(B);

    int ans = accumulate(v.begin(),v.end(),0);


    return ans ;

}


int add(int a, int b)
{
    while (b)
    {
        unsigned int c = a&b;

        a = a^b;

        b = c<<1;
    }

    return a ;
    
}

int main() 
{

    cout<<addNumbers(12,4)<<endl;

return 0;
}
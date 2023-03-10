#include <bits/stdc++.h>
using namespace std;

int main() 
{

    vector <int> v = {2,1,4,7,3,10,12,11,26};

    auto i =  upper_bound(v.begin(),v.end(),11);

    cout<<*i<<endl;

return 0;
}
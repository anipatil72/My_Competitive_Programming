#include <bits/stdc++.h>
using namespace std;

int main() 
{

    vector <int> v = {1,3,4,4,6,7,8,9,9};

    auto i =   upper_bound(v.begin(),v.end(),3);

    cout<<*i<<endl;

    cout<<distance(i,v.begin())<<endl;

    

return 0;
}
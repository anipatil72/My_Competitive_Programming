#include <bits/stdc++.h>
using namespace std;

int main() 
{

    unordered_map<int,int>m;

    for (int i = 0; i < 4; i++)
    {
            int d;

            cin>>d;

            m[d]++;
    }


    cout<<4-m.size()<<endl;
    

return 0;
}
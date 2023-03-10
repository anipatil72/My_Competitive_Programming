#include <bits/stdc++.h>
using namespace std;

int maxArea(vector<int> &height)
{

    int n = height.size();

    int mh = 0;

    vector<pair<int,int>> v(n);

    for (int i = 0; i < n; i++)
    {

        v.push_back({height[i],i+1});
            
    }

    sort(v.begin(),v.end());
    



   


    return mh;
    
}

int main()
{

    vector<int> v = {1};

    cout<<maxArea(v);

    return 0;
}
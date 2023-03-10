// ॥ श्री गणेशाय नमः ॥
 
#include <bits/stdc++.h>
#define ll long long
#define M 1000000007
using namespace std;

int main() 
{

    cout<<"Enter the size of the array : "<<endl;


    ll n;

    cin>>n;

    cout<<"Enter the elements of the array : "<<endl;

    vector<ll> a(n);

    for (ll i = 0; i < n; i++)
    {
            cin>>a[i];
    }

    sort(a.begin(), a.end());

    cout<<"Here is the sorted array : "<<endl;

    for (ll i = 0; i < n; i++)
    {
            cout<<a[i]<<" ";
    }
    

    
    

return 0;
}
 
// ॥ जय श्री राम जय श्री कृष्ण ॥
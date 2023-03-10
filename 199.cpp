#include <bits/stdc++.h>
typedef long long int  ll;


using namespace std;


ll mulmod(ll a, ll b, ll mod)
{
    ll res = 0; // Initialize result
    a = a % mod;
    while (b > 0)
    {
        // If b is odd, add 'a' to result
        if (b % 2 == 1)
            res = (res + a) % mod;
 
        // Multiply 'a' with 2
        a = (a * 2) % mod;
 
        // Divide b by 2
        b /= 2;
    }
 
    // Return result
    return res % mod;
}

int maxArea(int h, int w, vector<int> &horizontalCuts, vector<int> &verticalCuts)
{

    const int M = 1000000007;

    int m = horizontalCuts.size();
    int n = verticalCuts.size();

    sort(horizontalCuts.begin(), horizontalCuts.end());
    sort(verticalCuts.begin(), verticalCuts.end());

    horizontalCuts.insert(horizontalCuts.begin(), 0);
    horizontalCuts.insert(horizontalCuts.end(), h);

    verticalCuts.insert(verticalCuts.begin(), 0);
    verticalCuts.insert(verticalCuts.end(), w);

    int hmax = INT_MIN;
    int wmax = INT_MIN;

    m = horizontalCuts.size();
    n = verticalCuts.size();

    for (int i = 0; i < m - 1; i++)
    {

        hmax = max(horizontalCuts[i + 1] - horizontalCuts[i], hmax);
    }

    for (int i = 0; i < n- 1; i++)
    {
        wmax = max(verticalCuts[i + 1] - verticalCuts[i], wmax);
    }

    
     ll ans = mulmod(hmax,wmax,M);




    return ans; 

}  

int main()
{

    const int M = 1000000007;

    vector<int> h = {2};
    vector<int> w = {2};

    cout<<maxArea(1000000000,1000000000,h,w);

    //cout<<100000000%M;


    

    return 0;
}
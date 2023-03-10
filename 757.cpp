// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define M 1000000007
using namespace std;

void __print(int x) {cerr << x;}                                                                                                    
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '"' << x << '"';}
void __print(const string &x) {cerr << '"' << x << '"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," :""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

int jump(vector<int> &nums)
{
    int n = nums.size();

    if (n <= 2)
    {

        return n - 1;
    }

    vector<int> dp(n, 1e9);

    dp[n - 1] = 0;

    dp[n - 2] = 1;

    for (int i = n - 3; i >= 0; i--)
    {

        int t = nums[i];

        for (int j = 1; j <= t; j++)
        {

            if ((i + j) < n)
            {

                dp[i] = min(dp[i + j] + 1, dp[i]);
            }
        }
    }

    // debug(dp);

    return dp[0];
}

int main()
{

    vector<int> nums = {2,3,0,1,4};

    cout << jump(nums) << endl;

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
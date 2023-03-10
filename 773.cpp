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

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    int n = nums.size();

    vector<int> ans(n - k + 1);

    multiset<int> s;

    // int t = *max_element(s.begin(), s.end());

    for (int i = 0; i < k; i++)
    {

        s.insert(nums[i]);
    }

    int tt = 1;

    auto fd = s.end();

    fd--;

    ans[0] = *fd;

    // debug(s);

    for (int i = k; i < n; i++)
    {

        
        // s.erase(nums[i - k]);

        auto found = s.find(nums[i-k]);

        s.erase(found);

        s.insert(nums[i]);

        // debug(s);

        auto it = s.end();

        it--;

        ans[tt] = *it;

        tt++;
    }

    return ans;
}

int main()
{

    vector<int> nums = {-7, -8, 7, 5, 7, 1, 6, 0};

    vector<int> ans = maxSlidingWindow(nums, 4);

    for (int i = 0; i < ans.size(); i++)
    {

        cout << ans[i] << " ";
    }

    return 0;
}

// [-7,-8,7,5,7,1,6,0]
// 4

// ॥ जय श्री राम जय श्री कृष्ण ॥
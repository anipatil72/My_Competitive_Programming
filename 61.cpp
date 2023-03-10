#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
//typedef long long int ll1;
#define modulo 1000000007
#define PI 3.141592653589793238462643
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
fstream inp("input.txt",ios::in);
fstream out("output.txt",ios::out);
//oset<int>s:s.find_by_order(k):Kth element in "s",s.order_of_key(k):Number of item strictly lessthan k
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
template<class T> using orderedset =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;
/*ll bpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

bool prime[100000000];
ll spf[1000006];
void SieveOfEratosthenes(vector<ll>&ans)
{
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    //bool prime[n+1];
    memset(prime, true, sizeof(prime));

    for (int p=2; p*p<=1000005; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples of p
            for (int i=p*2; i<=1000005; i += p)
                prime[i] = false;
        }
    }

    // Print all prime numbers
    int cnt=0;
    for (int p = 2; p <= 1000005; p++)
        if (prime[p])
            {
              ans.push_back(p);
                cnt++;
            }
   // cout<<cnt<<"\n";
}
void smallestprime()
{
 for(int i=0;i<1000006;i++)
 {
    spf[i]=i;
 }
 for(int i=2;i<1000006;i++)
 {
    if((i%2)==0)
    spf[i]=2;
 }
 for(int i=3;i*i<1000006;i+=2)
 {
   if(spf[i]==i)
   {
    for(int j=i*i;j<1000006;j+=i)
    {
     if(spf[j]=j)
        spf[j]=i;
    }
   }
 }
}
void getFactorization(ll x,map<ll,ll>&ret)
{
    //vector<int> ret;
    while (x != 1)
    {
        ret[spf[x]]++;
        x = x / spf[x];
    }
    if(x==1)
        ret[1]++;
    //return ret;
}
int con(string s)
{
 int num=0;
 for(int i=0;i<s.length();i++)
 {
    num=num*10+(s[i]-'0');
 }
 return num;
}
void findSmallestNumber(ll n)
{

    // Iterate in range[N, N + 2520]
    ll no=ceil((1.0*n)/2520);
    no=no*2520;
    for (ll i = n; i <= no; ++i) {

        bool possible = 1;

        // Store the number in a temporary
        // variable
        ll temp = i;
        while (temp) {
            if (temp % 10 != 0) {
                int digit = temp % 10;
                if (i % digit != 0) {
                    possible = 0;
                    break;
                }
            }
            temp /= 10;
        }

        if (possible == 1) {
            cout << i;
            return;
        }
    }
}
ll countDivisibles(ll A, ll B, ll M)
{

    // Add 1 explicitly as A is divisible by M
    if (A % M == 0)
        return (B / M) - (A / M) + 1;

    // A is not divisible by M
    return (B / M) - (A / M);
}
ll fin(ll r,ll lcm,ll b)
{
 ll div=r/lcm;
 ll pro=div*lcm;
 ll tot=r;
 if(div!=0)
 {
    tot=tot-(div-1)*b;
    tot=tot-min(b,r-pro+1);
 }
 return tot-min(r,b-1);
}

//int dp[200005];
/*struct val
{
 int t,f,s;
};*/
/*bool comp(dimen &d1,dimen &d2)
{
// if(d1.h!=d2.h)
    return d1.h<d2.h;

}
map<ll,ll>mp;
void primeFactors(ll n)
{
    // Print the number of 2s that divide n
    while (n % 2 == 0)
    {
        mp[2]++;
        n = n/2;
    }

    // n must be odd at this point. So we can skip
    // one element (Note i = i +2)
    for (ll i = 3; i <= sqrt(n); i = i + 2)
    {
        // While i divides n, print i and divide n
        while (n % i == 0)
        {
           mp[i]++;
            n = n/i;
        }
    }

    // This condition is to handle the case when n
    // is a prime number greater than 2
    if (n > 2)
        mp[n]++;
}
//vector<vector<int>>adj;
/*bool comp(pair<ll,ll>&a,pair<ll,ll>&b)
{
 if(a.first!=b.first)
 {
    return a.first<b.first;
 }
 return a.second>b.second;
}
/*struct grp
{
 int p;
 int r;
};
struct grp par[1002];
struct grp par1[1002];
int fin(int val)
{
 if(par[val].p!=val)
    par[val].p=fin(par[val].p);

    return par[val].p;
}
int fin1(int val)
{
  if(par1[val].p!=val)
    par1[val].p=fin1(par1[val].p);

    return par1[val].p;
}
int merg(int u,int v)
{
  if(par[u].r<par[v].r)
    {par[u].p=v;
    // par[v].r++;
    }
  else if(par[v].r<par[u].r)
  {
    par[v].p=u;
    //par[u].r++;
  }
  else
  {
    par[v].p=u;
    par[u].r++;
  }
 //par[v]=par[u];
}
int merg1(int u,int v)
{
  if(par1[u].r<par1[v].r)
    {par1[u].p=v;
    // par1[v].r++;
    }
  else if(par1[v].r<par1[u].r)
  {
    par1[v].p=u;
   // par1[u].r++;
  }
  else
  {
    par1[v].p=u;
    par1[u].r++;
  }
}*/
/*int a[200005][2];
ll RightAngled( ll n)
{

    // To store the number of points
    // has same x or y coordinates
    unordered_map<ll,ll> xpoints;
    unordered_map<ll,ll> ypoints;

    for (ll i = 0; i < n; i++) {
        xpoints[a[i][0]]++;
        ypoints[a[i][1]]++;
    }

    // Store the total count of triangle
    ll cnt = 0;

    // Iterate to check for total number
    // of possible triangle
    for (ll i = 0; i < n; i++) {

        if (xpoints[a[i][0]] >= 1
            && ypoints[a[i][1]] >= 1) {

            // Add the count of triangles
            // formed
            cnt += (xpoints[a[i][0]] - 1)
                     * (ypoints[a[i][1]] - 1);
        }
    }

    // Total possible triangle
    return cnt;
}
bool comp(pair<ll,ll>&p1,pair<ll,ll>&p2)
{

    return p1.second< p2.second;
}
//vector<vector<int>>adj;
string solve(string a,string b)
{
 string r=b;
 int carry=0;
 int n=a.size(),m=b.size();
 for(int i=(m-1);i>=0;i--)
 {
    r[i]=b[i]+carry+((i>=(m-n))?(a[i-(m-n)]-'0'):0);
    if(r[i]>'9')
    {
     r[i]=r[i]-10;
     carry=1;
    }
    else
         carry=0;
 }
 return r;
}
//bool comp()
void convertTobasen(ll N,vector<ll>&v,ll k)
{
    // Base case
    if (N == 0)
        return;

    // Finding the remainder
    // when N is divided by 3
    ll x = N % k;
    N /= k;
    if (x < 0)
        N += 1;

    // Recursive function to
    // call the function for
    // the integer division
    // of the value N/3
    convertTobasen(N,v,k);

    // Handling the negative cases
    if (x < 0)
    {
        v.push_back(x + (k * -1));
    }
    else
        {
         v.push_back(x);
        }
}
*/
//int is1=0,is2=0;
/*int dp[51][51];
int maxi=INT_MIN;
int solve(string &s,string &s1,int n,int m)
{
 if(n==0||m==0)
    return 0;
 if(dp[n][m]!=-1)
    return dp[n][m];
    int c=0;
 if(s[n-1]==s1[m-1])
 {
   c=1+solve(s,s1,n-1,m-1);
   maxi=max(maxi,c);
 }
 dp[n][m]=c;
 solve(s,s1,n-1,m);
 solve(s,s1,n,m-1);
 return c;
}*/
/*bool chk(ll arr[],ll val,ll h)
{
 vector<ll>v;
 for(int i=0;i<val;i++)
 {
    v.push_back(arr[i]);
 }
 sort(v.begin(),v.end());
 ll p=h;
 for(int i=v.size()-1;i>=0;i=i-2)
 {
  p=p-v[i];
 }

 //cout<<"\n";
 if(p>=0)
    return true;
 else
    return false;
*/
ll stringTointeger(string str)
{
    ll temp = 0;
    for (ll i = 0; i < str.length(); i++) {


        temp = temp * 10 + (str[i] - '0');
    }
    return temp;
}
/*ll N;
    cin>>N;
     ll res = (ll)sqrt(N) + (ll)cbrt(N)
              - (ll)(sqrt(cbrt(N)));
              cout<<res<<"\n";*/
/*bool comp(pair<pair<ll,ll>,ll>&p,pair<pair<ll,ll>,ll>&p1)
{
 if(p1.first.first!=p.first.first)
 {
  return p.first.first<p1.first.first;
 }
 return p.first.second>p1.first.second;
}*/
 long long getcount(long long n, int k)
{
    // Store count till nearest
    // power of 2 less than N
    long long res = (n >> (k + 1)) << k;
    //cout<<res<<"\n";
    // If K-th bit is set in N
    if ((n >> k) & 1)

        // Add to result the nearest
        // power of 2 less than N
        res += n & ((1ll << k) - 1);

    // Return result
    return res;
}
/*ll solve(ll n,ll l)
{
 ll pw=(1<<l);
 if(n<pw)
    return 0;
 ll div=(n>>(l+1));
 ll rem=0;
 //if((n>>l)&1;
 pw--;
 if(((n>>l)&(ll)1))
 rem=n&(pw);
 return ((div<<l)+rem);
}*/
/*
bool solve(ll mid,ll h[],ll n)
{
 ll h1[n];
 for(int i=0;i<n;i++)
 {
    h1[i]=0;
 }
 for(int i=0;i<n;i++)
 {
    h1[i]=h[i];
 }
 //reverse(h1,h1+n);
 ll f=1;
 for(int i=n-1;i>=2;i--)
 {
    if(h1[i]<mid)
       {
        f=0;
        break;
       }
    ll rem=min(h1[i]-mid,h[i]);
    ll div=rem/3;
    h1[i]-=3*div;
    h1[i-1]+=div;
    h1[i-2]+=2*div;
 }
 for(int i=0;i<n;i++)
 {
    if(h1[i]<mid)
    {
     f=0;
     break;
    }
 }
 if(f==0)
    return false;
 else
    return true;
}*/
/*ll vis[51];
 vector<vector<ll>>adj;
 ll flag=0;
bool solve(ll u,ll n,ll arr[])
{
    if(u==n+1)
     {
        flag=1;
        return true;
     }
    for(auto it:adj[u])
    {
     //cout<<it<<" ";
     if(vis[it]==0)
     {
        vis[it]=1;
        if(solve(u+1,n,arr))
            return true;
        vis[it]=0;
     }
    }
    return false;
}*/
/*ll vis[27];
string solve(char c,map<char,vector<char>>&mp)
{
 vis[c-'a']=1;
 //cout<<c<<"\n";
 string ans;
 string left;
 string right;
 ll f=0;
 for(auto it:mp[c])
 {
 // char ch=it;
  //cout<<ch<<" ";
  if(vis[it-'a']==1)
     {  f=f^1;
        continue;
     }

  if(f==0)
  {
    left=solve(it,mp);
   // ans+=left;
   // ans+=c;
    f=f^1;
  }
  else
  {
    right=solve(it,mp);
   // ans+=right;
    f=f^1;
    break;
  }
 }

 ans+=left;
 //if(vis[c-'a']==0)
 ans+=c;
 ans+=right;

// cout<<left<<" "<<right<<"\n";
 return ans;
 //cout<<c<<" ";
 //cout<<left<<" "<<right<<"\n";
 //cout<<ans<<"\n";
}*/
/*ll solve(ll n)
{
 ll res=n;
 for(ll i=2;i*i<=n;i++)
 {
if(n%i==0)
   {res=res/i;
   res=res*((i-1));
   while(n%i==0)
    n=n/i;
   }
 }
 if(n>1)
 {
    res=res/n;
    res=res*(n-1);
 }
 return res;
}*/
/*int solve(ll n,ll arr[])
{
vector<ll>v;
v.push_back(arr[0]);
 for(int i=1;i<n;i++)
 {
    if(arr[i]>=v.back())
        v.push_back(arr[i]);
    else
    {
     ll ind=upper_bound(v.begin(),v.end(),arr[i])-v.begin();
     v[ind]=arr[i];
    }
 }
 return v.size();
}*/
// read question properly
// read the constraints
// think before typing
// then take edge cases
// then apply
//ll ans=INT_MAX;
/*ll dp[3501][3501];
ll solve(ll n,ll m,ll k,ll arr[],ll st,ll en)
{
 if((st-0)+((n-1)-en)==k+m-1-k)
 {
   // cout<<st<<" "<<en<<"\n";
   ll maxi=max(arr[st],arr[en]);
   return maxi;
 }
 if(dp[st][en]!=-1)
    return dp[st][en];
 ll maxi=INT_MAX;
 maxi=min(maxi,solve(n,m,k,arr,st+1,en));
 maxi=min(maxi,solve(n,m,k,arr,st,en-1));
 dp[st][en]=maxi;
 return maxi;
}*/
 /*ll solve(ll arr[],ll mid,ll n,ll h)
 {
    ll cost=0;
    for(int i=1;i<n;i++)
    {
     ll prev=arr[i-1];
     ll diff=abs(arr[i]-prev);
     if(diff==1)
     {
        if((i+1)<n)
        {
         ll diff1=abs(arr[i+1]-arr[i]);
         if(diff1==1)
         {
            i++;
            continue;
         }
         else
         {
            cost++;
         }
        }
        else
        {
         continue;
        }
     }
     else if(diff==2)
     {
      continue;
     }
     else
     {
      continue;
     }
    }
    if(cost<=mid)
        return 1;
    else
        return 0;
 }*/
 /*ll solve(ll arr[],ll arr1[],ll n,ll ind,ll pre[],ll pre1[],ll pre2[],ll pre3[])
 {
   if(ind>=n)
    {
     return 0;
    }
   ll maxi=INT_MAX;
   //ll prev=arr1[ind]*arr1[ind]+pre1[ind+1]*arr1[ind]+pre[ind+1]+arr[ind]*arr[ind]+pre2[ind+1]+pre3[ind+1]*arr[ind];
   //ll prev1=arr[ind]*arr[ind]+pre[ind+1]+pre1[ind+1]*arr[ind]+arr1[ind]*arr1[ind]+pre2[ind+1]+pre3[ind+1]*arr1[ind];
   ll prev=0;
   ll prev1=0;
   if((ind-1)>=0)
   {
    prev=pre[ind-1]+pre1[ind-1]*arr1[ind]+arr1[ind]*arr1[ind]*ind+pre2[ind-1]+pre3[ind-1]*arr[ind]+arr[ind]*arr[ind]*ind;
    prev1=pre[ind-1]+pre1[ind-1]*arr[ind]+arr[ind]*arr[ind]*ind+pre2[ind-1]+pre3[ind-1]*arr1[ind]+arr1[ind]*arr1[ind]*ind;
   }
   maxi=min(maxi,prev+solve(arr,arr1,n,ind+1,pre,pre1,pre2,pre3));
   maxi=min(maxi,prev1+solve(arr,arr1,n,ind+1,pre,pre1,pre2,pre3));
  // cout<<maxi<<"\n";
   return maxi;

 }*/
 /*map<char,vector<ll>>mp;
 ll solve(string &s,string &s1,ll ind,ll prev,ll n,ll m,ll mask)
 {
    if(ind==n)
        {
         return m-prev-1;
        }
   ll maxi=-1;
   for(int i=0;i<mp[s1[ind]].size();i++)
   {
     ll ind1=mp[s1[ind]][i];
   //  cout<<ind1<<" ";
     if((mask&(1<<ind1))==1||(ind1<=prev))
      continue;
    // cout<<ind1<<" "<<prev<<"\n";
     ll nwmask=mask|(1<<ind1);
     ll ans=solve(s,s1,ind+1,ind1,n,m,nwmask);
     if(ans!=-1)
     {
        maxi=max(maxi,ind-prev-1);
        maxi=max(maxi,ans);
     }
   }
   return maxi;
 }*/
 //vector<vector<ll>>adj;
 /*ll dp[43][17];
 //ll mini=1e13;
 ll solve(vector<ll>&fac,vector<ll>&pw,ll n,ll temp,ll st,ll st1)
 {

    if(temp>n)
        return 1e13;
    if(temp==n)
        return 0;
    if(st>=fac.size()&&st1>=pw.size())
        return 1e13;
     if(dp[st][st1]!=-1)
        return dp[st][st1];
    ll maxi=1e13;
    if(st<fac.size())
    maxi=min(maxi,1+solve(fac,pw,n,temp+fac[st],st+1,st1));
    if(st1<pw.size())
    maxi=min(maxi,1+solve(fac,pw,n,temp+pw[st1],st,st1+1));
    maxi=min(maxi,solve(fac,pw,n,temp,st+1,st1+1));
    dp[st][st1]=maxi;
    cout<<maxi<<"\n";
    return maxi;
 }*/
 //vector<vector<ll>>adj;
 //vector<ll>ans;
 //ll dp[100001][100001];
 //ll cnt=0;
 //ll ans1[100005];
 //ll dp[2][(1<<20)];

 bool comp(pair<ll,ll>&a,pair<ll,ll>&b)
 {
  if(a.first==b.first)
    return a.second>b.second;
  else
    return a.first>b.first;
 }
ll fact[200005];
ll ifact[200005];
void factorial()
{
 for(int i=0;i<200005;i++)
 {
    fact[i]=0;
    ifact[i]=0;
 }
 fact[0]=1;
 ifact[0]=1;
 for(int i=1;i<200005;i++)
 {
    fact[i]=((fact[i-1])*i)%modulo;
    ifact[i]=(expo(fact[i],modulo-2,modulo))%modulo;
 }
}
 ll dp[5002][5002];
 //ll ans=0;
 //vector<ll>ans2;
 /*void solve(ll ind,ll n,ll x,ll y,ll arr[],ll sum,vector<ll>&ans1)
 {
  if(ind==n)
  {
    ll rem=n*(n+1);
    rem=rem/2;
    ll rem1=rem-sum;
    if(sum*x-rem1*y==0)
    {
        ans2.clear();
     ans=1;
     for(int i=0;i<n;i++)
     {
        if(find(ans1.begin(),ans1.end(),arr[i])==ans1.end())
        {
         ans2.push_back(arr[i]);
        }
     }
    }
    //cout<<ans1.size()<<"\n";
   // ans2=ans1;
    return ;
  }
  ans1.push_back(arr[ind]);
  solve(ind+1,n,x,y,arr,sum+arr[ind],ans1);
  ans1.pop_back();
  solve(ind+1,n,x,y,arr,sum,ans1);
  return ;
 }*/


 int main()
 {
    fast
    ll t;
    cin>>t;
   // factorial();
    //ll t1=0;
    while(t--)
    {
     ll n;
     cin>>n;
     ll arr[n];
     for(int i=0;i<n;i++)
     {
        cin>>arr[i];
     }
      if(n==1)
      {
        cout<<"0"<<"\n";
        continue;
      }
      ll ind=0;
      ll prev=arr[0];
      ll ans=0;
      while(ind<n)
      {
        ll cnt=0;
        prev=arr[ind];
        ind++;
       while((ind<n)&&arr[ind]<prev)
       {
        cnt++;
        prev=arr[ind];
        ind++;
       }
      // cout<<cnt<<"\n";
       ans=ans+ceil(cnt/(2*1.0));


      }
      cout<<ans<<"\n";

    }
  }

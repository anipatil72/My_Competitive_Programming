#include <bits/stdc++.h>
using namespace std;

#define ll long long
//function to check prime
bool isPrime(int n)
{
if (n == 1)
{
return false;
}
if (n == 2 || n == 3)
{
return true;
}
if (n % 2 == 0 || n % 3 == 0)
{
return false;
}
for (int i = 5; i * i <= n; i = i + 6)
{
if (n % i == 0)
{
return false;
}
if (n % (i + 2) == 0)
{
return false;
}
}
return true;
}
//Sieve of Erathosthenes
vector<bool> sieve(int n)
{
vector <bool> v(n+1,true);
    for (int i = 2; i*i<=n ; i++)
     {
           if (v[i])
           {
              for (int j = i*i; j <=n;  j = i + j)
               {
                  v[j] = false;  
                }
            }
   }
  return v ;
}
         int GCD(int a, int b)
         {
            if (b == 0)
             {
                  return a;
             }
                   
             return GCD(b, a % b);
          }

          int LCM(int a,int b)
          {
              return (a*b)/GCD(a,b);
          }
// -------------------Important Notes------------------- //
// ***For Interactive Problems remember to remove multi test cases condition*** //
// (int)log2(x) + 1  -> to calculate number of bits of a number
// s.erase(0, min(s.find_first_not_of('0'), s.size()-1));   //for removing leading zero's
// Remember about unique function usage
// yi=(t|xi)⊕xi
// (int index = str.find(substr, pos)) != string::npos    // for checking substring 'substr' in string 'str'
// ((x >> j) & 1) ===> to check if the j-th bit is on/off
// x |= (1 << i) ===> to set the i-th bit on
 
void solve()
{

    ll n,m,d,temp,f,g,h,p;

    cin>>n>>m;

    vector<int> a;
    vector<int> r;




    for (int i = 0; i < n; i++)
    {
        cin>>d;
        

        a.push_back(d);

        if (d==p&&i>0)
        {
           temp ++ ;

           if (temp==m)
           {
                r.push_back(i);
           }

           continue;
                
        }

       
        p = d ;
        

        
    }
    




}


int main() 
{
  ll t ;


  cin>>t ;
 
          for (ll i = 0; i < t; i++)
          {
    solve();
          }
 
  return 0;
}
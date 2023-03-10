#include <bits/stdc++.h>
using namespace std;

#define ll long long
// function to check prime
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

// Sieve of Erathosthenes
vector<bool> sieve(int n)
{
    vector<bool> v(n + 1, true);
    for (int i = 2; i * i <= n; i++)
    {
        if (v[i])
        {
            for (int j = i * i; j <= n; j = i + j)
            {
                v[j] = false;
            }
        }
    }
    return v;
}

int GCD(int a, int b)
{
    if (b == 0)
    {
        return a;
    }

    return GCD(b, a % b);
}

int LCM(int a, int b)
{
    return (a * b) / GCD(a, b);
}

ll GiveNcR(int n, int r)
{

    // p holds the value of n*(n-1)*(n-2)...,
    // k holds the value of r*(r-1)...
    long long p = 1, k = 1;

    // C(n, r) == C(n, n-r),
    // choosing the smaller value
    if (n - r < r)
        r = n - r;

    if (r != 0)
    {
        while (r)
        {
            p *= n;
            k *= r;

            // gcd of p, k
            long long m = __gcd(p, k);

            // dividing by gcd, to simplify
            // product division by their gcd
            // saves from the overflow
            p /= m;
            k /= m;

            n--;
            r--;
        }

        // k should be simplified to 1
        // as C(n, r) is a natural number
        // (denominator should be 1 ) .
    }

    else
        p = 1;

    // if our approach is correct p = ans and k =1
    // cout << p << endl;

    return p;
}

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

// A function to perform division of large numbers
string longDivision(string number, int divisor)
{
    // As result can be very large store it in string
    string ans;

    // Find prefix of number that is larger
    // than divisor.
    int idx = 0;
    int temp = number[idx] - '0';
    while (temp < divisor)
        temp = temp * 10 + (number[++idx] - '0');

    // Repeatedly divide divisor with temp. After
    // every division, update temp to include one
    // more digit.
    while (number.size() > idx)
    {
        // Store result in answer i.e. temp / divisor
        ans += (temp / divisor) + '0';

        // Take next digit of number
        temp = (temp % divisor) * 10 + number[++idx] - '0';
    }

    // If divisor is greater than number
    if (ans.length() == 0)
    {
        return "0";
    }

    // else return ans
    {
        return ans;
    }
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

    int n , m;

    cin>>n>>m;

    int a[50][50] = {0}; 



    for (int i = 0; i < 50; i++)
    {

        if (i%4==0||i%4==3)
        {
            for (int j = 0; j < 50; j++)
            {
                if (j%4==0||j%4==3)
                {
                    a[i][j] = 1 ;
                }
                

                   
            }
                
        }


        if (i%4==1||i%4==2)
        {
            for (int j = 0; j < 50; j++)
            {
                if (j%4==1||j%4==2)
                {
                    a[i][j] = 1 ;
                }
            }
                
        }
        
            
    }


    for (int i = 0; i < n; i++)
    {
            for (int j = 0; j < m; j++)
            {
                    cout<<a[i][j]<<" ";
            }

            cout<<endl;
            
    }
    
    

    
    
}

int main()
{
    ll t;

    cin >> t;

    for (ll i = 0; i < t; i++)
    {
        solve();
    }

    
    

    return 0;
}
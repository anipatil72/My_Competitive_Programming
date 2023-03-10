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
long long GiveNcR(int n, int r)
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

    int basicSum = 0 ;

    ll n;
    cin >> n;

    basicSum++;
    ll f = 0;
    vector<ll> arr(n);


    //cout<<basicSum;
    set<ll> s;
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
        s.insert(arr[i]);
        if (arr[i] != 0)
            f = 1;
    }
    if (!f)
    {
        cout << "YES" << endl;
        ;
        return;
    }

    sort(arr.begin(), arr.end());



    map<ll, ll> cnt;




    for (ll i = 0; i < n; i++)
    {
        cnt[abs(arr[i])]++;
    }
    if (cnt.size() > 2)
    {
        cout << "NO" << endl;
        
    }
    else
    {
        if (n <= 10)
        {
            ll isP = 1;
            for (ll i = 0; i < n; i++)
            {
                for (ll j = i + 1; j < n; j++)
                {
                    for (ll k = j + 1; k < n; k++)
                    {
                        ll summ = arr[i] + arr[j] + arr[k];

                        if (s.count(summ))
                        {
                        }
                        else
                        {
                            isP = 0;
                        }
                    }
                }
            }
            if (isP)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
        else
        {
            cout << "NO" << endl;
        }
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
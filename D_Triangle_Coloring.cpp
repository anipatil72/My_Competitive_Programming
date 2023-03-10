// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define uint unsigned int
#define M 998244353

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

// returns map containing factor and multiplicity, Eg: 60 = {{2,2},{3,1},{5,1}}

map<long long, long long> factorize(long long n)
{
    map<long long, long long> ans;
    for (long long i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            ans[i]++;
            n /= i;
        }
    }
    if (n > 1)
    {
        ans[n]++;
        n = 1;
    }
    return ans;
}

template <int MOD>
class Modular
{
    // using ModInt = Modular<1'000'000'007>;
public:
    Modular(long long v = 0)
    {
        value = v % MOD;
        if (value < 0)
            value += MOD;
    }

    Modular(long long a, long long b) : value(0)
    {
        *this += a;
        *this /= b;
    }

    Modular &operator+=(Modular const &b)
    {
        value += b.value;
        if (value >= MOD)
            value -= MOD;
        return *this;
    }

    Modular &operator-=(Modular const &b)
    {
        value -= b.value;
        if (value < 0)
            value += MOD;
        return *this;
    }

    Modular &operator*=(Modular const &b)
    {
        value = (long long)value * b.value % MOD;
        return *this;
    }

    friend Modular power(Modular a, long long e)
    {
        Modular res = 1;
        while (e)
        {
            if (e & 1)
                res *= a;
            a *= a;
            e >>= 1;
        }
        return res;
    }

    friend Modular inverse(Modular a)
    {
        return power(a, MOD - 2);
    }

    Modular &operator/=(Modular const &b)
    {
        return *this *= inverse(b);
    }

    friend Modular operator+(Modular a, Modular const b)
    {
        return a += b;
    }

    friend Modular operator-(Modular a, Modular const b)
    {
        return a -= b;
    }

    friend Modular operator-(Modular const a)
    {
        return 0 - a;
    }

    friend Modular operator*(Modular a, Modular const b)
    {
        return a *= b;
    }

    friend Modular operator/(Modular a, Modular const b)
    {
        return a /= b;
    }

    friend std::ostream &operator<<(std::ostream &os, Modular const &a)
    {
        return os << a.value;
    }

    friend std::istream &operator>>(std::istream &is, Modular &a)
    {
        is >> a.value;
        a.value %= MOD;
        if (a.value < 0)
            a.value += MOD;
        return is;
    }

    friend bool operator==(Modular const &a, Modular const &b)
    {
        return a.value == b.value;
    }

    friend bool operator!=(Modular const &a, Modular const &b)
    {
        return a.value != b.value;
    }

    friend Modular &operator++(Modular &a, int)
    {
        return a += 1;
    }

    friend Modular operator++(Modular const &a, int)
    {
        return Modular(a)++;
    }

    friend Modular &operator--(Modular &a, int)
    {
        return a -= 1;
    }

    friend Modular operator--(Modular const &a, int)
    {
        return Modular(a)--;
    }

    int value;
    static const int MOD_value = MOD;
};

// -------------------Important Notes------------------- //
// ***For Interactive Problems remember to remove multi test cases condition*** //
// (int)log2(x) + 1  -> to calculate number of bits of a number
// s.erase(0, min(s.find_first_not_of('0'), s.size()-1));   //for removing leading zero's
// Remember about unique function usage
// yi=(t|xi)⊕xi
// (int index = str.find(substr, pos)) != string::npos    // for checking substring 'substr' in string 'str'
// ((x >> j) & 1) ===> to check if the j-th bit is on/off
// x |= (1 << i) ===> to set the i-th bit on

void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '"' << x << '"'; }
void __print(const string &x) { cerr << '"' << x << '"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V> &x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}
#ifndef ONLINE_JUDGE
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif

int GiveNcRmod(int n, int r)
{

    // p holds the value of n*(n-1)*(n-2)...,
    // k holds the value of r*(r-1)...
    long long p = 1, k = 1;
    Modular<M> a = 1, b = 1;

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
            // If asked Modulo

            a *= n;
            b *= r;

            // gcd of p, k
            // long long m = __gcd(p, k);

            // dividing by gcd, to simplify
            // product division by their gcd
            // saves from the overflow
            // p /= m;
            // k /= m;

            n--;
            r--;
        }

        // k should be simplified to 1
        // as C(n, r) is a natural number
        // (denominator should be 1 ) .
    }
    else
    {
        p = 1;
    }
    a /= b;

    // return the remainder value

    int x = a.value;

    return x;
}

void solve()
{

    int n;

    cin >> n;

    Modular<M> ans = 1;

    for (int i = 0; i < n / 3; i++)
    {

        int d, maxi = INT_MIN;

        // cin>>a>>b>>c;

        unordered_map<int, int> m;

        for (int j = 0; j < 3; j++)
        {
            cin >> d;

            maxi = max(maxi, d);

            m[d]++;
        }

        ans *= m[maxi];

        // cout << ans << endl;
        // debug(m);
    }

    ans*=GiveNcRmod(n/3, n/6);

    // ans*=2;

    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t = 1;

    // cin >> t;

    for (ll i = 0; i < t; i++)
    {
        solve();
    }

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
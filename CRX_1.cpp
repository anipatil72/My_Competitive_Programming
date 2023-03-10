// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define M (int)1e9 + 7
using namespace std;

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

void solve()
{

    int a, b, c;

    int odd = 0, even = 0;

    cin >> a >> b >> c;

    if ((a + b) > 0 && (a + b) % 2 == 0)
    {
        cout << "YES" << endl;

        return;
    }

    if ((c + b) > 0 && (c + b) % 2 == 0)
    {
        cout << "YES" << endl;

        return;
    }

    if ((a + c) > 0 && (a + c) % 2 == 0)
    {
        cout << "YES" << endl;

        return;
    }

    cout << "NO" << endl;
}

int main()
{

    // Modular<M> m = 1;

    // for (int i = 0; i < 10; i++)
    // {

    //     m*=2;

    //     cout<<m<<endl;
            
    // }
    



    // int t = 1;

    // // cin>>t;

    // for (int i = 0; i < t; i++)
    // {
    //     solve();
    // }

    // return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
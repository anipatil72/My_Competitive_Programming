// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;
using namespace __gnu_pbds;

vector<int> smallest_factor;
vector<bool> prime;
vector<int> primes;

void sieve(int maximum)
{
    maximum = max(maximum, 1);
    smallest_factor.assign(maximum + 1, 0);
    prime.assign(maximum + 1, true);
    prime[0] = prime[1] = false;
    primes = {};

    for (int p = 2; p <= maximum; p++)
        if (prime[p])
        {
            smallest_factor[p] = p;
            primes.push_back(p);

            for (int64_t i = int64_t(p) * p; i <= maximum; i += p)
                if (prime[i])
                {
                    prime[i] = false;
                    smallest_factor[i] = p;
                }
        }
}

// Determines whether n is prime in worst case O(sqrt n / log n). Requires having run `sieve` up to at least sqrt(n).
// If we've run `sieve` up to at least n, takes O(1) time.
bool is_prime(int64_t n)
{
    int64_t sieve_max = int64_t(smallest_factor.size()) - 1;
    assert(1 <= n && n <= sieve_max * sieve_max);

    if (n <= sieve_max)
        return prime[n];

    for (int64_t p : primes)
    {
        if (p * p > n)
            break;

        if (n % p == 0)
            return false;
    }

    return true;
}

// Prime factorizes n in worst case O(sqrt n / log n). Requires having run `sieve` up to at least sqrt(n).
// If we've run `sieve` up to at least n, takes O(log n) time.
template <typename T>
vector<pair<T, int>> prime_factorize(T n)
{
    int64_t sieve_max = int64_t(smallest_factor.size()) - 1;
    assert(1 <= n && n <= sieve_max * sieve_max);
    vector<pair<T, int>> result;

    if (n <= sieve_max)
    {
        while (n != 1)
        {
            int p = smallest_factor[n];
            int exponent = 0;

            do
            {
                n /= p;
                exponent++;
            } while (n % p == 0);

            result.emplace_back(p, exponent);
        }

        return result;
    }

    for (int p : primes)
    {
        if (int64_t(p) * p > n)
            break;

        if (n % p == 0)
        {
            result.emplace_back(p, 0);

            do
            {
                n /= p;
                result.back().second++;
            } while (n % p == 0);
        }
    }

    if (n > 1)
        result.emplace_back(n, 1);

    return result;
}

int bulbSwitch(int n)
{

    // sieve(n);

    long long sq = (int)sqrt(n);

    // long long tem = primes.size();

    return sq;
}

int main()
{
    // int n = 329;

    // sieve(2);

    // // cout << is_prime(n) << endl;

    // cout << "This is teh size of teh primes array : " << primes.size() << endl;

    cout << bulbSwitch(1) << endl;
    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
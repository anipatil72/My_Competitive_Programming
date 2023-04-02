// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;

int64_t inv_mod(int64_t a, int64_t m)
{
    // https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm#Example
    int64_t g = m, r = a, x = 0, y = 1;

    while (r != 0)
    {
        int64_t q = g / r;
        g %= r;
        swap(g, r);
        x -= q * y;
        swap(x, y);
    }

    assert(g == 1);
    assert(y == m || y == -m);
    return x < 0 ? x + m : x;
}

// Returns a number that is a1 mod m1 and a2 mod m2. Assumes m1 and m2 are relatively prime.
int64_t chinese_remainder_theorem(int64_t a1, int64_t m1, int64_t a2, int64_t m2)
{
    if (m1 < m2)
        return chinese_remainder_theorem(a2, m2, a1, m1);

    // assert(__gcd(m1, m2) == 1);
    assert(m1 >= m2);
    int64_t k = (a2 - a1) % m2 * inv_mod(m1, m2) % m2;
    int64_t result = a1 + k * m1;

    if (result < 0)
        result += m1 * m2;

    assert(0 <= result && result < m1 * m2);
    assert(result % m1 == a1 && result % m2 == a2);
    return result;
}

int64_t non_relatively_prime_crt(int64_t a1, int64_t m1, int64_t a2, int64_t m2)
{
    int64_t g = gcd(m1, m2);

    if (a1 % g != a2 % g)
        return -1;

    return chinese_remainder_theorem(a1 / g, m1 / g, a2 / g, m2 / g) * g + a1 % g;
}

template <typename T_vector>
void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1)
{
    if (start < 0)
        start = 0;
    if (end < 0)
        end = int(v.size());

    for (int i = start; i < end; i++)
    {

        if (i == end - 1)
        {
            cout << v[i] + (add_one ? 1 : 0) << endl;
        }
        else
        {
            cout << v[i] + (add_one ? 1 : 0) << ' ';
        }
    }
}

vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
{
    int n = spells.size();

    int m = potions.size();

    sort(potions.begin(), potions.end());

    vector<int> ans(n);

    for (int i = 0; i < n; i++)
    {
        long long req = (success % spells[i] == 0 ? success / spells[i] : success / spells[i] + 1);

        // cout << req << endl;

        auto it = lower_bound(potions.begin(), potions.end(), req);

        int num = potions.end() - it;

        ans[i] = num;
    }

    return ans;
}

int main()
{

    vector<int> spells = {3, 1, 2};
    vector<int> potions = {8, 5, 8};

    ll success = 16;

    vector<int> ans = successfulPairs(spells, potions, success);

    output_vector(ans);

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
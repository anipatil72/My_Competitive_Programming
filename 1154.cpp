// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

pair<long long, long long> Minmax(int A, int B)
{
    long long max_connections, min_connections;

    // Computing maximum connections
    long long x = A - (B - 1); // Houses in the largest locality
    max_connections = (x * (x - 1)) / 2;

    // Computing minimum connections
    long long y = A / B; // Evenly divided houses among all localities
    long long z = A % B; // Houses which are extra and need to be accommodated

    min_connections = z * (y * (y + 1)) / 2 + (B - z) * (y * (y - 1)) / 2;

    return {min_connections, max_connections};
}

int main()
{
    int A, B;
    cin >> A >> B;
    pair<long long, long long> result = Minmax(A, B);
    cout << result.first << " " << result.second << endl;
    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
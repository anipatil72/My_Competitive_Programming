// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;
using namespace __gnu_pbds;

double average(vector<int> &salary)
{
    int n = salary.size();

    double sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += salary[i];
    }

    sum -= (*max_element(salary.begin(), salary.end()) + *min_element(salary.begin(), salary.end()));

    sum /= (n - 2);

    return sum;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
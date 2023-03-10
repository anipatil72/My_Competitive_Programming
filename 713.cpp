// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#define ll long long
#define M 1000000007
using namespace std;

int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    long long sum1 = accumulate(gas.begin(), gas.end(), 0LL);

    long long sum2 = accumulate(cost.begin(), cost.end(), 0LL);

    if (sum1<sum2)
    {
            return -1;

    }

    auto it = max_element(gas.begin(), gas.end());

    return it - gas.begin();
    


}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
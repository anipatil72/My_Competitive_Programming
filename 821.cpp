// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;

int numRescueBoats(vector<int> &people, int limit)
{
    int n = people.size();

    sort(people.begin(), people.end());

    int left = 0, right = n - 1;

    int boats = 0;

    while (left <= right)
    {
        if (left == right)
        {
            boats++;

            break;
        }

        long long cur = people[left] + people[right];

        if (cur > limit)
        {
            boats++;

            right--;
        }
        else
        {
            left++;

            right--;

            boats++;
        }
    }

    return boats;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
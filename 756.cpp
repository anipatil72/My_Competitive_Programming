// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define M 1000000007
using namespace std;

int totalFruit(vector<int> &a)
{
    int n = a.size();

    if (n <= 2)
    {
        return n;
    }

    int ans = 2;

    int left = 0;

    int right = left + 1;

    unordered_map<int, int> m;

    m[a[left]]++;

    int count = 0;

    cout << "This is left : " << left << " This is right : " << right << endl;

    while (right < n)
    {
        while (right < n && m.size() <= 2)
        {

            m[a[right]]++;

            right++;

            cout << "This is left : " << left << " This is right : " << right << endl;
        }

        ans = max(ans, right - left);

        while (left + 1 < right && m.size() >= 3)
        {
            m[a[left]]--;

            cout << "This is left : " << left << " This is right : " << right << endl;

            if (m[a[left]] == 0)
            {
                m.erase(a[left]);
            }

            left++;
        }

        cout << "This is left : " << left << " This is right : " << right << endl;
    }

    return ans;
}

// [0,1,6,6,4,4,6]

// [3,3,3,1,2,1,1,2,3,3,4]

int main()
{

    vector<int> fruits = {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};

    cout << totalFruit(fruits);

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
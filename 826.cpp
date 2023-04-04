// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;

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

int partitionString(string s)
{
    int n = s.length();

    vector<int> ref(26, 1);

    int left = 0, right = 0;

    vector<int> temp = ref;

    int ans = 0;

    // temp[s[0] - '0'] = 0;

    int count = 0;

    while (right < n)
    {
        if (temp[s[right] - 'a'])
        {
            temp[s[right] - 'a'] = 0;

            count++;
        }
        else
        {
            temp = ref;

            // cout << "Here : " << right << endl;

            temp[s[right] - 'a'] = 0;

            ans++;

            count = 1;
        }
        right++;
    }

    ans++;

    return ans;
}

int main()
{

    string s = "ssssss";

    cout << partitionString(s);

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
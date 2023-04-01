// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;

void printvector(vector<int> &a)
{

    int n = a.size();

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    cout << endl;
}

class ManacherAlgorithm
{
    vector<int> p;

public:
    void run_manacher(string s)
    {
        int n = s.length();

        // cout << s << endl;

        for (int i = 0; i < n; i++)
        {
            cout << s[i] << " ";
        }

        cout << endl;

        p.assign(n, 1);

        int left = 1, right = 1;

        for (int i = 1; i < n; i++)
        {
            p[i] = max(0, min(right - i, p[left + right - i]));

            while (i + p[i] < n && i - p[i] >= 0 && s[i + p[i]] == s[i - p[i]])
            {
                p[i]++;
            }

            if (i + p[i] > right)
            {
                left = i - p[i];

                right = i + p[i];
            }
        }

        printvector(p);
    }

    ManacherAlgorithm(string s)
    {

        string t = "";

        for (auto v : s)
        {

            t += '#';

            t += v;
        }

        t += '#';

        // cout << t << endl;

        run_manacher(t);
    }

    int getLongestPalindrome(int center, bool odd)
    {
        int pos = 2 * center + 1 + (!odd);

        return p[pos - 1];
    }

    bool checkPalindrome(int left, int right)
    {
        int dis = right - left + 1;

        return (dis <= getLongestPalindrome((left + right) / 2, left % 2 == right % 2));
    }

    vector<int> getPArray()
    {
        return p;
    }
};

int main()
{

    string s = "babbabbabc";

    ManacherAlgorithm manus(s);

    cout << manus.getLongestPalindrome(3, 0);

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
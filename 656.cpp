// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
using namespace std;

int compress(vector<char> &chars)
{
    int n = chars.size();

    string ans = "";

    int i = 0;

    while (i < n)
    {
        char cur = chars[i];

        int count = 0;

        while (i < n && chars[i] == cur)
        {
            i++;
            count++;
        }

        ans += cur;

        if (count > 1)
        {
            ans += to_string(count);
        }
    }

    chars.clear();

    for (int j = 0; j < ans.length(); j++)
    {

        char d = ans[j];

        chars.push_back(d);
    }

    return ans.length();
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
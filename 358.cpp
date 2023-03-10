#include <bits/stdc++.h>
using namespace std;

void helper(string& ans)
    {
        // reverse(ans.begin(),ans.end());

        int n = ans.length();

        if (n==1)
        {
            return;
        }

        for (int i = 0; i < n/2; i++)
        {
                ans[i]  = ans[n-1-i];
        }
        
        
        
        
            
    }

int Reverse(int x)
{

    bool flag = false;

    if (x < 0)
    {
        flag = true;
    }

    string s = to_string(x);

    string ans;

    int i = 0;

    if (flag)
    {
        i++;

        ans = s.substr(i);

        reverse(ans.begin(), ans.end());

        long long a = stoll(ans);

        a = -1 * a;

        if (a < INT_MIN)
        {
            return 0;
        }
        else
        {
            return a;
        }
    }

    ans = s.substr(i);

    reverse(ans.begin(), ans.end());

    long long a = stoll(ans);

    if (a > INT_MAX)
    {
        return 0;
    }

    return a;
}

int main()
{

    int a = -1234;

    cout<<

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

string solve(string A, string B)
{

    int n = A.length();
    int m = B.length();

    unordered_map<char, int> s;

    int x = 0;

    int y = 0;

    for (int i = 0; i < n; i++)
    {

        if (A[i]==B[i])
        {
                
            x++;
            continue;
        }
        
        s[A[i]]++;
    }

    for (int i = 0; i < m; i++)
    {
        if (s[B[i]] > 0&&B[i]!=A[i])
        {

            y++;
            s[B[i]]--;
        }
    }

    string ans = to_string(x) + "A" + to_string(y) + "B";

    return ans;
}

int main()
{

    string secret = "3978973343647409";
    string guess = "1890771099992259";

     
     

    cout << solve(secret, guess);

    return 0;
}
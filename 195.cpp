#include <bits/stdc++.h>
using namespace std;

bool isvalidRange(string s)
{
    if (stoi(s) > 255 or stoi(s) < 0)
        return false;
    if (s.size() > 1 and s[0] == '0')
        return false;

        
    return true;
}

void helper(string s, int idx, string ip, int ipPos, vector<string> &ans)
{
    if (idx == s.size() and ipPos == 5)
    {
        ip = ip.substr(0, ip.size() - 1);
        ans.push_back(ip);
        return;
    }
    if (idx >= s.size())
    {
        return;
    }
    if (idx < s.size() and ipPos > 4)
    {
        return;
    }

    string A = s.substr(idx, 1);
    if (isvalidRange(A))
    {
        helper(s, idx + 1, ip + A + ".", ipPos + 1, ans);
    }

    A = s.substr(idx, 2);
    if (isvalidRange(A))
    {
        helper(s, idx + 2, ip + A + ".", ipPos + 1, ans);
    }

    A = s.substr(idx, 3);
    if (isvalidRange(A))
    {
        helper(s, idx + 3, ip + A + ".", ipPos + 1, ans);
    }
}

vector<string> restoreIpAddresses(string A)
{
    vector<string> ans;
    helper(A, 0, "", 1, ans);
    return ans;
}

int main()
{

    string s = "25525511135";

    string s1;

    s1.assign(s.begin() + 2, s.begin() + 5);

    cout << s1 << endl;

    return 0;
}
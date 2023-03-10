#include <bits/stdc++.h>
using namespace std;

void recur(vector<string> &v, string &t, string &s, int k)
{

    int n = s.length();

    if (k == n)
    {

        v.push_back(t);

        

        return;
    }

    recur(v, t, s, k + 1);

    string d = t + s[k];
    recur(v, d, s, k + 1);
}

vector<string> subsets(string s)
{

    vector<string> ans;
    int n = s.length();

    string temp = "";

    recur(ans, temp, s, 0);

    return ans;
}

int main()
{

    string s = "abc";

    vector<string> a = subsets(s);

    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << "\n";
    }

    return 0;
}
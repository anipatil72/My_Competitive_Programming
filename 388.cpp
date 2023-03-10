#include <bits/stdc++.h>
using namespace std;

void recur(unordered_map<string,int>& m, string &t, int n)
{
    if (n == 0)
    {
        // ans.push_back(t);
        // cout<<t<<"\n";

        if (m.count(t)==0)
        {
                m[t]++;
        }
        
        return;
    }

    int a = t.size();

    string params = "()";

    for (int i = 0; i < a; i++)
    {
        t.insert(t.begin() + i, params.begin(), params.end());

        recur(m, t, n - 1);

        t.erase(t.begin() + i, t.begin() + i + 2);
    }
}

vector<string> generateParenthesis(int n)
{
    unordered_map<string,int> m;


    string t = "()";

    recur(m,t,n -1);

    vector<string> ans;

    for (auto i = m.begin(); i != m.end(); i++)
    {
         ans.push_back(i->first);   
    }
    

    return ans;
}

int main()
{
    vector<string> ans = generateParenthesis(3);

    int n = ans.size();




    // string s = "abcdef";

    // // string r = "xyz";

    // cout<<s<<endl;

    // // s.insert(s.begin() + 1,r.begin(),r.end());

    // s.erase(s.begin()+1,s.begin()+4);

    // cout<<s<<endl;

    for (int i = 0; i < n; i++)
    {
            cout<<ans[i]<<"\n";
    }
    

    return 0;
}
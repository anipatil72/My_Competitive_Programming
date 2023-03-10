#include <bits/stdc++.h>
using namespace std;

void patternMatch(string s, string p)
{

    int n = s.length();
    int m = p.length();

    //cout<<n<<" "<<m<<endl;

    for (int i = 0; i < n - m + 1; i++)
    {

        string s1 = s.substr(i, m);

        cout << s1 << endl;

        // if (s1 == p)
        // {
        //     cout<<i<<" ";
        // }
    }

}

int main()
{

    patternMatch("geeksforgeeks", "aaa");

    return 0;
}
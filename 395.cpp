#include <bits/stdc++.h>
using namespace std;

int recur(vector<int> &v, int s, int e,int sum)
{
    if (s == e - 1)
    {

        return max(v[s], v[e]);
    }

    return max(sum - recur(v,s + 1,e,sum - v[s]),sum - recur(v,s,e-1,sum - v[e]));
}

int game(vector<int> &v)
{
    int n = v.size();

    int mi = 0;
    int fr = 0;

    int start = 0;
    int end = n - 1;

    int sum = accumulate(v.begin(),v.end(),0);

         

    return recur(v, start, end,sum);
}

int main()
{

    vector<int> v = {2, 3, 15, 7};

    cout << game(v);

    return 0;
}
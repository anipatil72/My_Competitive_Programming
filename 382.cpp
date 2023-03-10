#include <bits/stdc++.h>
using namespace std;

// bool myComp(pair<int,int> p, pair<int,int> q)
// {
//     int a = p.first;
//     int b = q.first;

//     int x= p.second;
//     int y = q.second;

//     float f = (1.0 * a)/x;
//     float g = (1.0 * b)/y;

//     if (f==g)
//     {
//             return p.second<q.second;
//     }

//     return f<g;

// }

void recur(vector<int> &v, vector<int> &w, int sum, int &m, int cur, int index)
{
    if (sum < 0)
    {
        return;
    }

    if (sum >= 0)
    {
        m = max(m, cur);
    }

    for (int i = index; i < v.size(); i++)
    {
        recur(v, w, sum, m, cur, i + 1);
        recur(v, w, sum - w[i], m, cur + v[i], i + 1);
    }
}

int knapsack(vector<int> &v, vector<int> &w, int sum)
{
    int n = v.size();

    // vector<pair<int, int>> greedy(n);

    // for (int i = 0; i < n; i++)
    // {
    //     greedy[i] = {v[i], w[i]};
    // }

    // sort(greedy.begin(),greedy.end(),myComp);

    int ans = INT_MIN;
    
    int cur =  0;
    int index = 0;

    recur(v,w,sum,ans,cur,index);

    if (ans==INT_MIN)
    {
         return -1;   
    }


    return ans;
    
}

int main()
{

    vector<int> v = {60,100,120};
    vector<int> w = {10,20,30};

    int n = v.size();

    cout<<knapsack(v,w,0);

    // vector<pair<int, int>> greedy(n);

    // for (int i = 0; i < n; i++)
    // {
    //     greedy[i] = {v[i], w[i]};
    // }

    // for (int i = 0; i < n; i++)
    // {
    //         cout<<greedy[i].first<<" "<<greedy[i].second<<endl;
    // }

    return 0;
}
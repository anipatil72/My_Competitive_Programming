#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(const vector<int> &A, int B)
{

    int n = A.size();

    vector<int> ans(2,0);

    unordered_map<int,vector<int>>m;

    for (int i = 0; i < n; i++)
    {
            m[A[i]].push_back(i);
    }

    bool flag = 0 ;

    for (int i = n-1; i >=0; i--)
    {
        int d = B - A[i];


        if (m.count(d)>0&&m[B-A[i]][0]<i)
        {
            ans[0] = i + 1;    
            ans[1] = m[B-A[i]][0] + 1; 
            // return ans;  

            flag = 1;
        }
        
    }

    if (flag)
    {
            return ans;
    }
    
    
    
    return {};

}

int main()
{

    return 0;
}
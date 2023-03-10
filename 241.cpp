#include <bits/stdc++.h>
using namespace std;

int minCostClimbingStairs(vector<int> &cost)
{

    int n= cost.size();

    if (n==1)
    {
            return cost[0];
    }

    int sum = 0 ;
    


    int cur = 0 ;

    if (cost[0]>cost[1])
    {
            cur = 1 ;

    }

    while (cur<n)
    {

        sum+= cost[cur];
        if (cost[cur+1]>cost[cur+2])
        {
            cur = cur + 2 ;
        }
        else
        {
            cur +=1 ;
        }
        
        
    }

    
    return sum;
    



}

int main()
{

    return 0;
}
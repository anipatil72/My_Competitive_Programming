#include <bits/stdc++.h>
using namespace std;

int furthestBuilding(vector<int> &heights, int bricks, int ladders)
{

    int lc = ladders, bc = bricks;

    int ans = -1;

    int n = heights.size();

    for (int i = 0; i < n - 1; i++)
    {
        if (heights[i] < heights[i + 1] && lc > 0)
        {
            lc--;
            continue;
        }

        if (lc == 0 && heights[i] < heights[i + 1] && bc > 0)
        {

            if (bc>=heights[i+1]-heights[i])
            {
                bc = bc - heights[i + 1] + heights[i];
                    
            }

            else
            {
                return i ;
            }
            
            

        }

        if (lc == 0 && bc == 0 && heights[i] < heights[i + 1])
        {
            return i;
        }
    }

    return n - 1;
}

int main()
{

    vector <int> h = {4,12,2,7,3,18,20,3,19};

    int b = 10, l = 2;

    cout<<furthestBuilding(h,b,l)<<endl;

    return 0;
}
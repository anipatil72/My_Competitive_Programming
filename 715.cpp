// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#define ll long long
#define M 1000000007
using namespace std;

int captureForts(vector<int> &forts)
{

    int n = forts.size();

    int temp = 4;

    int index = 0;

    int ans = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (forts[i] == 0)
        {
        }
        else if (forts[i] == 1 || forts[i] == -1)
        {
            if (temp == 4)
            {
                temp = forts[i];

                index = i;
            }
            else
            {

                if (forts[i] == temp)
                {
                    temp = forts[i];

                    index = i;
                }
                else
                {
                    temp = forts[i];

                    ans = max(ans, i - index - 1);

                    index = i ;
                }
            }
        }
    }

    if (ans==INT_MIN)
    {
        return 0 ;    
    }
    

    return ans;
}

int main()
{

    vector<int> forts = {0, 0, 1, -1};


    cout<<captureForts(forts);



    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
using namespace std;

vector<int> lexicalOrder(int n)
{
    vector<int> ans = {};

    vector<int> a = {0,1,2,3,4,5,6,7,8,9};

    // vector<int> pos(10, 0);



    for (int i = 1; i < 10; i++)
    {

        for (int j = 0; j <= 9; j++)
        {
            string s = to_string(i);

            while (stoll(s)<=n)
            {
                ans.push_back(stoll(s));

                s+= to_string(j);
            }
                
        }
        

        

        
        

        
        
            
    }
    

    int start = 0;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
#include <bits/stdc++.h>
using namespace std;

vector<int> solve(int A, vector<int> &B, vector<vector<int>> &C, int D)
{

    int n = A;

    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        int price = B[i];

        for (int j = 0; j < C.size(); j++)
        {
            if ((C[j][0]== i + 1)&&(C[j][1]!=i+1))
            {
                  price = min(price, C[j][2] + B[C[j][1] - 1] + D*C[j][2]);  
            }
            else if ((C[j][0]!= i + 1)&&(C[j][1]==i+1))
            {
                  price = min(price, C[j][2] + B[C[j][0] - 1] + D*C[j][2]);  
            }
            
        }

        ans.push_back(price);
        
    }

    return ans;
    
}

int main()
{

    return 0;
}
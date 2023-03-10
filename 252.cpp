#include <bits/stdc++.h>
using namespace std;

string LCS(string &a, string &b)
{
    string ans = "";

    int m = a.length();
    int n = b.length();

    int dp[m + 1][n + 1];

    for (int i = 0; i < m + 1; i++)
    {
        dp[i][0] = 0;
    }

    for (int i = 0; i < n + 1; i++)
    {
        dp[0][i] = 0;
    }

    for (int i = 1; i < m + 1; i++)
    {

        for (int j = 1; j < n + 1; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                // ans += a[i - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }


    // for (int i = 0; i < m+1; i++)
    // {
    //         for (int j = 0; j < n+1; j++)
    //         {
    //                 cout<<dp[i][j]<<" ";
    //         }


    //         cout<<endl;

    // }


    int i = n , j = m ;




    while (i>0&&j>0)
    {
        if (a[i-1]==b[j-1])
        {
            ans+=a[i-1];

            // cout<<"I am at index i "<<i<<" j "<<j<<endl;
            i--;
            j--;
        }
        
         else if (dp[i-1][j]>dp[i][j-1])
         {
            // cout<<"I am at index i "<<i<<" j "<<j<<endl;
                 i--;
         }
         else
         {
            // cout<<"I am at index i "<<i<<" j "<<j<<endl;
             j--;
         }
      
        
    }
    

    // return dp[m][n];
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{

    string a = "Iam";
    string b = "Image";

    string s = LCS(a, b);

    // int s = LCS(a,b);

    cout << s << endl;

    return 0;
}
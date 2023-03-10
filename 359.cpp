#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string> &strs)
{

    int n = strs.size();

    string ans = "";

    
    int i = 0;

    while (i<strs[0].length())
    {

        char check = strs[0][i];
        bool flag = false;

        for (int j = 1; j < n; j++)
        {
              if (i>=strs[j].length()||check!=strs[j][i])
              {

                    flag = true;
                    break;
              }
                
        }

        if (flag)
        {
            break;
        }
        

        ans+=check;

        i++;
        
    }
    

    return ans;
}

int main()
{

    return 0;
}
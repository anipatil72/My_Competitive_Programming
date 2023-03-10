#include <bits/stdc++.h>
using namespace std;

int solve(string A)
{

    vector<int> c(26,0);

    int n = A.size();

    for (int i = 0; i < n; i++)
    {
            c[A[i]-'a']++;
    }

        int count = 0;


    for (int i = 0; i < 26; i++)
    {

        if (c[i]%2!=0)
        {
                count++;
        }
        

        if (count>=2)
        {
            return 0;
        }
        
        
        
        
    }


    return 1;
    
    
}

int main()
{

    return 0;
}
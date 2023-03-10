#include <bits/stdc++.h>
using namespace std;

int main() 
{

    int n;
    cin>>n;

    int cur = n+1;


    while (true)
    {

        bool flag = true;
        string t = to_string(cur);

        for (int i = 0; i < 4; i++)
        {
                for (int j = i + 1; j < 4; j++)
                {
                       if (t[i]==t[j])
                       {
                           flag = false;
                           break; 
                       }
                        
                }

                if (!flag)
                {
                    break;    
                }
                
                
        }

        if (flag)
        {
                break;
        }
        
        cur++;
        
    }

    cout<<cur<<endl;
    

return 0;
}
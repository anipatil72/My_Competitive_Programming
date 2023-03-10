#include <bits/stdc++.h>
using namespace std;

int main() 
{

    int n;

    int M ;



    cin>>n;

    cin>>M;

    int m = INT_MIN;

    int index = 0;

    for (int i = 0; i < n; i++)
    {

        int d;

        cin>>d;


        if (d%M==0&&d/M>=m)
        {
            m = d/M;

            index = i + 1;
        }
        else if (d%M!=0&&d/M  + 1>=m)
        {
            m = d/M + 1;

            index = i + 1;
            
        }
        
             
    }

    cout<<index<<endl;
    

return 0;
}
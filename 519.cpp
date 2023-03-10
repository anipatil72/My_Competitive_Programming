#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;

    cin >> n;

    int a = 0, b = 0;

    for (int i = 0; i < n; i++)
    {
        int d;

        cin >> d;

        if (d == 5)
        {
            b++;
        }
        else
        {
            a++;
        }
    }

    if (a>0&&b/9>0)
    {
        string s = "";

        int x = b/9;

        x = x* 9;



        for (int j = 0; j < x; j++)
        {
                s+="5";


        }

        for (int j = 0; j < a; j++)
        {
            s+="0";
        }

        cout<<s<<endl;
        
            
    }
    else if(a>0)
    {
        cout<<0<<endl;
    }
    else
    {
        cout<<"-1"<<endl;
    }
    
    
    

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> prettyPrint(int A)
{
    int s = 2*A - 1;

    vector<vector<int>> v(s);


    for (int i = 0; i < s; i++)
    {
        for (int i = 0; i < s; i++)
        {
            v[i].push_back(0);
        }
            
    }


    // for (int i = 0; i < s; i++)
    // {
    //         for (int j = 0; j < s; j++)
    //         {
    //                 cout<<v[i][j]<<" ";

    //         }

    //         cout<<endl;
            
    // }
    
    

    int cur = A;

    int right = 2*A - 2, left = 0;

    while (right >= left)
    {

        cout<<left<<" "<<right<<endl;
        for (int i = left; i <= right; i++)
        {

            cout<<"I am here"<<endl;
            v[left][i] = cur;
            v[right][i] = cur;

            v[i][left] = cur;
            v[i][right] = cur;
        }

        left++;
        right--;
        cur--;
    }

    return v ;
}

int main()
{

    vector<vector<int>> a;

    a = prettyPrint(3);

    

    for (int i = 0; i < a.size(); i++)
    {

        for (int j = 0; j < a.size(); j++)
        {
                cout<<a[i][j]<<" ";

        }
        
            cout<<endl;
    }
    



    return 0;
}
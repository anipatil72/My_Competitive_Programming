#include <bits/stdc++.h>
using namespace std;

void twoODD(vector<int> v)
{
    int x, y, z, f, g, h;

    bool b = 1;

    x = 0;

    for (int i = 0; i < v.size(); i++)
    {
        x = x ^ v[i];
    }

    int fix = x;

    y = x;

    cout<<y<<endl;

    for (int i = 0; i < v.size(); i++)
    {


        //cout<<((y^v[i])^y)<<" ";

        
        
            cout<<((y ^ v[i]) ^ y)<<" ";
        
        

        // if (((y ^ v[i]) ^ y != v[i]) && b)
        // {
        //     z = v[i];
        //     b = 0;
        // }

        // if (((y ^ v[i]) ^ y != v[i]) && v[i] != z)
        // {
        //     f = v[i];
        //     break;
        // }
    }

    //cout << "The two odd occuring elements are " << z << " " << f << endl;
}

int main()
{

    vector<int> v = {3, 4, 3, 4, 5, 4, 4, 6, 7, 7};

    twoODD(v);

    return 0;
}
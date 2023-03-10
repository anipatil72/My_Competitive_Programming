#include <bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int> &a)
{

    int n = a.size();

    int i = 0, j = 0;

    while (j < n && i < n)
    {
        if (a[j] == 0)
        {
            while (j < n && a[j] == 0)
            {
                j++;
            }

            if (j == n)
            {
                break;
            }

            a[i] = a[j];

            i++;
            j++;
        }
        else
        {
            a[i] = a[j];
            i++;
            j++;
        }
    }


    for (int k = i; k < n; k++)
    {
         a[k] = 0;   
    }
    
}

int main()
{

    vector<int> v = {0,1,3,0,2, 0,0,0};

    moveZeroes(v);

    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";

    }
    

    return 0;
}
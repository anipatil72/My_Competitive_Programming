#include <bits/stdc++.h>
using namespace std;

bool myComp(vector<int> &a, vector<int> &b)
{
    return a[1] > b[1];
}

int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
{

    int n = boxTypes.size();

    int sum = 0;

    int boxSum = 0;

    sort(boxTypes.begin(), boxTypes.end(), myComp);

    // for (int i = 0; i < n; i++)
    // {
    //         for (int j = 0; j < 2; j++)
    //         {
    //                 cout<<boxTypes[i][j]<<" ";
    //         }

    //         cout<<endl;
            
    // }
    

    for (int i = 0; i < n; i++)
    {
        if (truckSize >= boxSum + boxTypes[i][0])
        {
            sum += boxTypes[i][0] * boxTypes[i][1];
            boxSum += boxTypes[i][0];
        }

        else if (boxSum + boxTypes[i][0] > truckSize)
        {
            sum += (truckSize - boxSum) * boxTypes[i][1];

            boxSum = truckSize;

            break;
        }


        //cout<<"The value of sum is "<<sum<<endl;
    }

    return sum;
}

int main()
{

    vector<vector<int>> v = {{5,10}, {2,5}, {4,7},{3,9}};

    cout<<maximumUnits(v,10);

    return 0;
}
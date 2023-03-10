#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int subarraysDivByK(vector<int> &nums, int k)

{
    int c = 0;

    vector<int>::iterator i, j, h;

    for (i = nums.begin(); i <= nums.end() - 1; i++)
    {

        for (j = i; j <= nums.end() - 1; j++)
        {

            int sum = 0;
            for (h = i; h <= j; h++)
            {

                sum = sum + *h;
            }

            if (sum % k == 0)
            {
                c++;
            }
        }
    }

    return c;
}

int main()
{

    vector<int> v = {4,5,0,-2,-3,1,85,0,41};

    vector <int> :: iterator i,j,k;

    for ( i = v.begin(); i <v.end(); i++)
    {
       cout<<*i<<" ";
    }
    sort(v.begin(),v.end());

    cout<<"\nAfter sorting\n";

    for ( i = v.begin(); i <v.end(); i++)
    {
       cout<<*i<<" ";
    }
    
    // vector<int> v1 = {5};

    //vector<int>::iterator p, q, r;

    // p = v.begin();
    // q = v.end()-1;

    // cout<<*p<<endl;
    // cout<<*q<<endl;

    // int ans = subarraysDivByK(v1, 9);

    // cout << ans << endl;



    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Solution
{

    public :
    int maxArr(vector<int> &A);

};

int Solution::maxArr(vector<int> &A)
{
    vector<int> sub(A.size(), 0);
    vector<int> add(A.size(), 0);
    int maxsub = INT_MIN;
    int minsub = INT_MAX;
    int maxadd = INT_MIN;
    int minadd = INT_MAX;

    int maxfn = 0;

    for (int i = 0; i < A.size(); i++)
    {

        sub[i] = A[i] - i;
        add[i] = A[i] + i;
        if (minsub > sub[i])
        {

            minsub = sub[i];
        }
        if (maxsub < sub[i])
        {

            maxsub = sub[i];
        }
        if (minadd > add[i])
            {
                minadd = add[i];
            }
        if (maxadd < add[i])
        {
            maxadd = add[i];

        }
    }
    maxfn = max(abs(maxadd - minadd), abs(maxsub - minsub));
    return maxfn;
}



int main()
{
    Solution o ;

    vector<int> v = {-39, -24, 82, 95, 91, -65, 16, -76, -56, 70};

    int r = o.maxArr(v); 

    cout << r<< endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class NumArray
{
public:
    vector<int> a;
    vector<int> p;
    NumArray(vector<int> &nums)
    {

        a = nums;
    }

    void update(int index, int val)
    {
        a[index] = val;
    }


    int helper(int left, int right)
    {
        int n = a.size();

        p.push_back(a[0]);

        int s = a[0];

        for (int i = 1; i < n; i++)
        {
            s+=a[i];
            p.push_back(s); 
        }

        if (left==0)
        {
                return p[right];
        }


        return p[right] - p[left-1];
        
    }

    int sumRange(int left, int right)
    {

        
        


    }
};

int main()
{

    return 0;
}
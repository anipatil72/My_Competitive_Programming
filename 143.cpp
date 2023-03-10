#include <bits/stdc++.h>
using namespace std;

vector<int> addArrays(vector<int> &A, vector<int> &B)
{

    int m = max(A.size(), B.size());

    vector<int> ans(m, 0);

    int n = min(A.size(), B.size());

    if (A.size() > B.size())
    {
        int i = A.size() - 1;
        int j = B.size() - 1;
        while (j >= 0)
        {

            int t = A[i] + B[j];

            if (t >= 10)
            {
                ans[i] = t % 10;
                A[i - 1] += t / 10;
                i--;
                j--;
                continue;
            }

            ans[i] = t;

            i--;
            j--;
        }

        while (i > 0)
        {

            int t = A[i];

            if (t >= 10)
            {
                ans[i] = t % 10;
                A[i - 1] += t / 10;
                i--;
                continue;

            }

            ans[i] = t ;
            i--;
        }

        if (A[0] == 10)
        {
            ans[0] = 0;

            ans.insert(ans.begin(), 1);
        }
    }

    if (B.size()>A.size())
    {

        int i = B.size() - 1;
        int j = A.size() - 1;
        while (j >= 0)
        {

            int t = A[i] + B[j];

            if (t >= 10)
            {
                ans[i] = t % 10;
                B[i - 1] += t / 10;
                i--;
                j--;
                continue;
            }

            ans[i] = t;

            i--;
            j--;
        }

        while (i > 0)
        {

            int t = B[i];

            if (t >= 10)
            {
                ans[i] = t % 10;
                B[i - 1] += t / 10;
                i--;
                continue;
            }

            ans[i] = t ;

            i--;
        }

        if (B[0] == 10)
        {
            ans[0] = 0;

            ans.insert(ans.begin(), 1);
        }
        
    }

    if (A.size()==B.size())
    {
            int i = A.size() - 1;
            
        while (i >= 0)
        {

            int t = A[i] + B[i];

            if (t >= 10)
            {
                ans[i] = t % 10;
                A[i - 1] += t / 10;
                i--;
                continue;
            }

            ans[i] = t;

            i--;
            
        }


        if (A[0] == 10)
        {
            ans[0] = 0;

            ans.insert(ans.begin(), 1);
        }
    }
    
    return ans ;
}

int main()
{

    vector<int> a = {9, 9, 1};
    vector<int> b = {1, 2, 1};

    vector<int> v = addArrays(a,b);

    for (int i = 0; i < v.size(); i++)
    {
            cout<<v[i]<<" ";
    }
    

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

bool mycomp(string s1,string s2)
{

    // string s1 = to_string(a);
    // string s2 = to_string(b);

   return (s1 + s2 > s2 + s1);

   //return a + 1> b ;
}

vector<int> nextPermutation1(vector<int> &A)
{
    int n=A.size(),s=-1,g=-1;
    for(int i=n-2;i>=0;i--)
    {
        if(A[i]<A[i+1])
        {
            s=i;
            break;
        }
    }
    if(s==-1)
    {
        sort(A.begin(),A.end());
    }
    else
    {
        for(int i=n-1;i>s;i--)
        {
            if(A[i]>A[s])
            {
                g=i;
                break;
            }
        }
        swap(A[s],A[g]);
        sort(A.begin()+s + 1,A.end());
    }
    return A;
}

vector<int> nextPermutation(vector<int> &A)
{
    int n=A.size(),s=-1,g=-1;
    for(int i=n-2;i>=0;i--)
    {
        if(A[i]<A[i+1])
        {
            s=i;
            break;
        }
    }
    if(s==-1)
    {
        sort(A.begin(),A.end());
    }
    else
    {
        // for(int i=n-1;i>s;i--)
        // {
        //     if(A[i]>A[s])
        //     {
        //         g=i;
        //         break;
        //     }
        // }
        // swap(A[s],A[g]);
        sort(A.begin()+s,A.end());
    }
    return A;
}

int main()
{

    vector<int> v = {1,9,6,5};
    // int a[] = {9, 6, 3};

    // reverse(v.begin(),v.end());

    // //cout<<mycomp(2,20);

    vector<int> a = nextPermutation(v);

    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}
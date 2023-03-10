#include <bits/stdc++.h>
using namespace std;

int kthSmallest(vector<vector<int> > &matrix, int k)
{
    priority_queue<int> pq;
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            pq.push(matrix[i][j]);
            if (pq.size() > k)
            {
                pq.pop();
            }
        }
    }
    return pq.top();
}

int main()
{

    cout<<"Enter the size : "<<endl;

    int n ;

    cin>>n;



    vector<int> a(n);

    cout<<"Enter the array : "<<endl;

    for(int i = 0  ; i< n; i++)
    {

        cin>>a[i];
    }

    sort(a.begin(), a.end());

    cout<<"The sorted array is : "<<endl;

    for(int i = 0 ; i< n; i++)
    {

        cout<<a[i]<<" ";
    }



    return 0;
}

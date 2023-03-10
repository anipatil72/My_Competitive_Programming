#include <bits/stdc++.h>
using namespace std;

void merge(int a[], int b[], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        if (a[i] > b[0])
        {
            pop_heap(b, b + n, greater<int>());

            swap(a[i], b[n - 1]);

            push_heap(b, b + n, greater<int>());

        }
    
    }


    sort_heap(b,b+n,greater<int>());

    reverse(b,b+n);

}

int main()
{

    int a[] = {30, 40,100,1003};
    int b[] = {2,8,9, 10,200,1000};

    int m = sizeof(a)/sizeof(int);

    int n = sizeof(b)/sizeof(int);


    merge(a,b,m,n);


    cout<<"After all"<<endl;

    for (int i = 0; i < m; i++)
    {
            cout<<a[i]<<" ";

    }


    cout<<endl;


    for (int i = 0; i < n; i++)
    {
            cout<<b[i]<<" ";
    }
    
    

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int kthsmallest(const vector<int> &A, int B)
{

    int n = A.size();

    priority_queue<int> q;

    for (int i = 0; i < B; i++)
    {
        q.push(A[i]);
    }

    for (int i = B; i < n; i++)
    {
        if (q.top() >= A[i])
        {
            q.pop();
            q.push(A[i]);
        }
    }

    return q.top();
}

int main()
{

    return 0;
}
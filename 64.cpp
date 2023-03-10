#include <bits/stdc++.h>
using namespace std;

void printKM(int a[], int n, int k)
{
    deque<int> dq;

    for (int i = 0; i < k; i++)
    {
        while (!dq.empty() && a[i] > a[dq.back()])
        {
            dq.pop_back();
        }

        dq.push_back(i);
    }

    for (int i = k; i < n; i++)
    {

        cout << a[dq.front()] << " ";
        while (!dq.empty() && dq.front() <= i - k)
        {
            dq.pop_front();
        }

        while (!dq.empty() && a[i] > a[dq.back()])
        {
            dq.pop_back();
        }

        dq.push_back(i);
    }

    cout << a[dq.front()] << endl;
}

void PrintM(int a[], int n, int k)
{
    deque<int> q;

    q.push_back(a[0]);

    for (int i = 1; i < n; i++)
    {
        if (q.size() == k)
        {
            q.pop_front();
        }

        if (q.size() != k && q.front() > a[i])
        {
            while (q.back() < a[i])
            {
                q.pop_back();
            }

            q.push_back(a[i]);
        }

        if (q.size() != k && q.front() < a[i])
        {
            q.clear();
            q.push_back(a[i]);
        }

        if (i + 1 >= k)
        {
            cout << q.front() << " ";
        }
    }
}

int main()
{

    int arr[] = {10, 80, 5, 12, 15, 71, 6};

    int s = sizeof(arr) / sizeof(int);

    printKM(arr, s, 3);

    return 0;
}
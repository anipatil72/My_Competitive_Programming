#include <bits/stdc++.h>
using namespace std;

void findMedian(int *arr, int n)
{

    priority_queue<int> max;

    priority_queue<int, vector<int>, greater<int>> min;

    max.push(arr[0]);

    cout << max.top()<<" ";

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < max.top())
        {
            max.push(arr[i]);
        }

        if (arr[i] >= max.top())
        {
            min.push(arr[i]);
        }

        if (max.size() > min.size() + 1)
        {
            int d = max.top();
            max.pop();
            min.push(d);
        }

        if (max.size() + 1 < min.size())
        {
            int d = min.top();
            min.pop();
            max.push(d);
        }

        if ((i + 1) % 2 == 0)
        {

            int g = (min.top() + max.top()) / 2;
            cout << g << " ";
        }

        if ((i + 1) % 2 != 0)
        {

            int f;

            if (max.size()>min.size())
            {
                f = max.top();
            }

            if (min.size()>max.size())
            {
                f = min.top();
            }

            cout << f << " ";
        }
    }
}

int main()
{

    int a[] = {6,2,1,3,7,5};

    findMedian(a, 6);

    return 0;
}
// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

class QueueStack
{
private:
    queue<int> q1;
    queue<int> q2;

public:
    void push(int);
    int pop();
};

// Function to push an element into stack using two queues.
void QueueStack ::push(int x)
{
    // Your Code

    // q1.push(x);

    if (q1.empty())
    {
        q2.push(x);
    }
    else
    {
        q1.push(x);
    }
}

// Function to pop an element from stack using two queues.
int QueueStack ::pop()
{
    if (q1.empty() && q2.empty())
    {
        return -1;
    }

    if (q1.empty())
    {
        while (q2.size() != 1)
        {
            int t = q2.front();

            q2.pop();

            q1.push(t);
        }

        int fr = q2.front();

        q2.pop();

        return fr;
    }

    while (q1.size() != 1)
    {
        int t = q1.front();

        q1.pop();

        q2.push(t);
    }

    int fr = q1.front();

    q1.pop();

    return fr;

    // Your Code
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
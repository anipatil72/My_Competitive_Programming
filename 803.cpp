// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;

class Solution
{
    int minEle;
    stack<int> s;

public:
    /*returns min element from stack*/
    int getMin()
    {
        return minEle;
        // Write your code here
    }

    /*returns poped element from stack*/
    int pop()
    {

        int cur = s.top();

        if (cur >= minEle)
        {

            s.pop();
        }
        else
        {
            minEle = 2 * minEle - cur;

            s.pop();
        }

        return cur;

        // Write your code here
    }

    /*push element x into the stack*/
    void push(int x)
    {

        if (s.size() == 0)
        {
            minEle = x;

            s.push(x);
        }
        else
        {
            if (x < minEle)
            {
                s.push(2 * x - minEle);

                minEle = x;
            }
            else
            {
                s.push(x);
            }
        }

        // Write your code here
    }
};

int main()
{

    stack<int> s;

    s.push(1);
    s.push(5);
    s.push(-1);
    s.push(10);

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
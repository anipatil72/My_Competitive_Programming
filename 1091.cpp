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

class twoStacks
{
    int *arr;
    int size;
    int top1, top2;

public:
    twoStacks(int n = 100)
    {
        size = n;
        arr = new int[n];
        top1 = -1;
        top2 = size;
    }

    // Function to push an integer into the stack1.
    void push1(int x)
    {
        arr[++top1] = x;
    }

    // Function to push an integer into the stack2.
    void push2(int x)
    {
        arr[--top2] = x;
    }

    // Function to remove an element from top of the stack1.
    int pop1()
    {

        if (top1 == -1)
        {
            return -1;
        }

        return arr[top1--];
    }

    // Function to remove an element from top of the stack2.
    int pop2()
    {
        if (top2 == size)
        {
            return -1;
        }

        return arr[top2++];
    }
};

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
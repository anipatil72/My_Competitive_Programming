#include <bits/stdc++.h>
using namespace std;

int guess(int num)
{
}

int guessNumber(int n)
{
    

    if (n == 1)
    {
        return 1;
    }

    int right = n;

    int left = 1;

    while (right > left)
    {
        int mid = (left + right) / 2;

        if (guess(left) == 0)
        {
            return left;
        }
        else if (guess(right) == 0)
        {
            return right;
        }
        else if (guess(mid) == 0)
        {
            return mid;
        }
        else if (guess(mid) == -1)
        {
            right = mid - 1;
            left++;
        }
        else if (guess(mid) == 1)
        {
            left = mid + 1;
            right--;
        }
    }

    return 0;
}

int main()
{

    return 0;
}
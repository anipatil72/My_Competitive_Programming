#include <bits/stdc++.h>
using namespace std;

vector<int> plusOne(vector<int> &digits)
{

    int n = digits.size();

    if (digits[n - 1] < 9)
    {
        digits[n - 1] += 1;

        return digits;
    }

    int carry = 1;

    int i = n - 1;

    while (i >= 0 && digits[i] == 9)
    {
        digits[i] = 0;
        i--;
        //    carry = 1;
    }

    if (i != -1)
    {
        digits[i] += 1;
    }
    else
    {
        digits.insert(digits.begin(), 1);
    }

    return digits;
}

int main()
{

    return 0;
}
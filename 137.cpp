#include <bits/stdc++.h>
using namespace std;

vector<int> repeatedNumber(const vector<int> &A)
{

    int n = A.size();
    long int actualSum = 0;
    long int Sum1ToN = long(n * long(n + 1)) / 2;
    long int Sum1ToN2 = long(n * long(n + 1) * long(2 * n + 1)) / 6;
    long int actualSumOfSquares = 0;

    for (int i = 0; i < n; i++)
    {
        actualSum += A[i];
        actualSumOfSquares += long(A[i]) * long(A[i]);
    }

    long int a_minus_b = actualSum - Sum1ToN;
    long int a2_minus_b2 = actualSumOfSquares - Sum1ToN2;
    long int a_plus_b = a2_minus_b2 / a_minus_b;

    long int a = long(a_minus_b + a_plus_b) / 2;
    long int b = a_plus_b - a;

    return {a, b};
}

int main()
{

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int permuteStrings(string A, string B)
{

    bool n = is_permutation(A.begin(), A.end(), B.begin());

    return n;
}

int main()
{

    string A = "scaler", B = "relacs";

    cout<<permuteStrings(A,B);

    return 0;
}
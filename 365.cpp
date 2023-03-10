#include <bits/stdc++.h>
using namespace std;

int findCount(const vector<int> &A, int B)
{

    int n = A.size();

    auto l = lower_bound(A.begin(),A.end(),B);
    auto h = upper_bound(A.begin(),A.end(),B);

    return distance(l,h);

}

int main()
{

    return 0;
}
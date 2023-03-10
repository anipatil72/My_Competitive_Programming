#include <bits/stdc++.h>
using namespace std;

int repeatedNumber(const vector<int> &A)
{

    int cand1 = -1, cand2 = -1;
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] == cand1)
        {
            cnt1++;
        }
        else if (A[i] == cand2)
        {
            cnt2++;
        }
        else if (cnt1 == 0)
        {
            cand1 = A[i];
            cnt1 = 1;
        }
        else if (cnt2 == 0)
        {
            cand2 = A[i];
            cnt2 = 1;
        }
        else
        {
            cnt1--;
            cnt2--;
        }
    }
    cnt1 = 0;
    cnt2 = 0;
    for (auto i : A)
    {
        if (i == cand1)
            cnt1++;
    }
    for (auto i : A)
    {
        if (i == cand2)
            cnt2++;
    }
    if (cnt1 > A.size() / 3)
    {
        return cand1;
    }
    else if (cnt2 > A.size() / 3)
    {
        return cand2;
    }
    return -1;
}

int main()
{

    vector<int> v = {1, 2, 3, 1, 1};

    cout << repeatedNumber(v);

    return 0;
}
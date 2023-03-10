#include <bits/stdc++.h>
using namespace std;

vector<int> wave(vector<int> &A)
{

    sort(A.begin(), A.end());

    for (int i = 0; i < A.size() - 1; i = i + 2)
    {
        swap(A[i], A[i + 1]);
    }

    return A ;
}

int main()
{

    vector<int> v = {5, 1, 3, 2, 4};

    vector<int> a = wave(v);

    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}
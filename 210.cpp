#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &A)
{

    assert(A.size() >= 1 && A.size() <= 1e5);
    // int n = A.size();

    int count = 0 ;

    int i = 0;

    while (i < A.size())
    {

        if (A[i] == 0)
        {
            count++;
            A.erase(A.begin() + i);
            // i++;
            continue;
        }

        i++;
    }

    for (int i = 0; i < count; i++)
    {
        A.push_back(0);
    }

    //cout<<count<<endl;

    return A;
}

int main()
{

    vector<int> a = {1,0, 6, 0,9,70,5,6,0,0,0};

    vector<int> b = solve(a);

    for (int i = 0; i < b.size(); i++)
    {
        cout << b[i] << " ";
    }

    return 0;
}
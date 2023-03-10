#include <bits/stdc++.h>
using namespace std;

bool myComp(vector<string>&a,vector<string> &b)
{
    return a[0]<b[0];
}

int highestScore(vector<vector<string>> &A)
{



    vector<int> m;

    sort(A.begin(),A.end(),myComp);

    int n = A.size();

    long long temp = stoll(A[0][1]);

    string name = A[0][0];

    int count = 1;

    for (int i = 1; i < n; i++)
    {

        if (A[i][0] == name)
        {
            temp += stoll(A[i][1]);
            count++;
            continue;
        }

        long long avg = temp / count;

        m.push_back(avg);

        name = A[i][0];

        count = 1;

        temp = stoll(A[i][1]);
    }

    long long av = temp / count;

    m.push_back(av);

    int M = INT_MIN;

    for (int i = 0; i < m.size(); i++)
    {

       // cout << m[i] << endl;
          M = max(m[i],M);
    }

    return M;
}

int main()
{

    vector<vector<string>> v = {{"Bob", "80"}, {"Bob", "90"}, {"Alice", "90"},{"Alice", "10"}};

    cout << highestScore(v) << endl;

    return 0;
}
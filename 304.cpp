#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generate(int numRows)
{

    vector<vector<int>> v;

    for (int i = 1; i <= numRows; i++)
    {

        vector<int> t(i, 1);

        v.push_back(t);
    }

    for (int i = 2; i < numRows; i++)
    {

        for (int j = 1; j < v[i].size() - 1; j++)
        {

            v[i][j] = v[i - 1][j - 1] + v[i - 1][j];
        }
    }

    return v;
}

int main()
{

    vector<vector<int>> a = generate(4);

    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a[i].size(); j++)
        {
            cout << a[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}
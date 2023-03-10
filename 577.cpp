#include <bits/stdc++.h>
using namespace std;

int match(vector<vector<int>> &a, vector<vector<int>> &b)
{

    int count = 0, n = a.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == 1 && b[i][j] == 1)
            {
                count++;
            }
        }
    }

    return count;
}

int right1(vector<vector<int>> a, vector<vector<int>> b, int row, int col)
{
    int n = a.size();

    vector<int> add(n, 0);

    for (int i = 0; i < row; i++)
    {
        a.insert(a.begin(), add);

        a.pop_back();
    }

    for (int i = 0; i < col; i++)
    {

        for (int j = 0; j < n; j++)
        {
            a[j].insert(a[j].begin(), 0);

            a[j].pop_back();
        }
    }

    // cout << "This is right1"
    //      << " ";
    // cout << "Where row = " << row << "and col = " << col << endl;

    // // cout<<"This is a : "<<endl;

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << a[i][j] << " ";
    //     }

    //     cout << endl;
    // }

    return match(a, b);
}
int right2(vector<vector<int>> a, vector<vector<int>> b, int row, int col)
{
    int n = a.size();

    vector<int> add(n, 0);

    for (int i = 0; i < row; i++)
    {
        // a.insert(a.begin(), add);

        a.push_back(add);

        a.erase(a.begin());

        // a.pop_back();
    }

    for (int i = 0; i < col; i++)
    {

        for (int j = 0; j < n; j++)
        {
            a[j].insert(a[j].begin(), 0);

            a[j].pop_back();
        }
    }

    // cout << "This is right2"
    //      << " ";
    // cout << "Where row = " << row << "and col = " << col << endl;

    // // cout<<"This is a : "<<endl;

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << a[i][j] << " ";
    //     }

    //     cout << endl;
    // }

    return match(a, b);
}

int left1(vector<vector<int>> a, vector<vector<int>> b, int row, int col)
{

    int n = a.size();

    vector<int> add(n, 0);

    for (int i = 0; i < row; i++)
    {
        a.push_back(add);

        a.erase(a.begin());
    }

    for (int i = 0; i < col; i++)
    {

        for (int j = 0; j < n; j++)
        {
            a[j].push_back(0);

            a[j].erase(a[j].begin());
        }
    }

    // cout << "This is left1"
    //      << " ";

    // cout << "Where row = " << row << "and col = " << col << endl;
    // cout << "This is a : " << endl;

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << a[i][j] << " ";
    //     }

    //     cout << endl;
    // }

    // cout<<"This is a : "<<endl;

    return match(a, b);
}

int left2(vector<vector<int>> a, vector<vector<int>> b, int row, int col)
{

    int n = a.size();

    vector<int> add(n, 0);

    for (int i = 0; i < row; i++)
    {
        // a.push_back( add);

        a.pop_back();

        // a.erase(a.begin());

        a.insert(a.begin(), add);
    }

    for (int i = 0; i < col; i++)
    {

        for (int j = 0; j < n; j++)
        {
            a[j].push_back(0);

            a[j].erase(a[j].begin());
        }
    }

    // cout << "This is left2"
    //      << " ";
    // cout << "Where row = " << row << "and col = " << col << endl;

    // // cout<<"This is a : "<<endl;

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << a[i][j] << " ";
    //     }

    //     cout << endl;
    // }

    return match(a, b);
}

int largestOverlap(vector<vector<int>> &img1, vector<vector<int>> &img2)
{

    int n = img1.size();

    if (n == 1)
    {
        if (img1[0][0] == 1 && img2[0][0] == 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    int M = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            M = max(M, right1(img1, img2, i, j));
            M = max(M, right2(img1, img2, i, j));
            M = max(M, left1(img1, img2, i, j));
            M = max(M, left2(img1, img2, i, j));
        }
    }

    return M;
}

int main()
{

    vector<vector<int>> a = {{0, 0, 0, 0, 1}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}};
    vector<vector<int>> b = {{0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {1, 0, 0, 0, 0}};

    cout << largestOverlap(a, b);
    return 0;
}
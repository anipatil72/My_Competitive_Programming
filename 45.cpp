#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<pair<int, char>> v;

    v.push_back({1, 'c'});
    v.push_back({3, 't'});
    v.push_back({2, 'a'});

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].second << " ";
    }

    cout<<endl;
    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].second << " ";
    }

    return 0;
}
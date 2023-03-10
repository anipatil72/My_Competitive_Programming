#include <bits/stdc++.h>
using namespace std;

int nthUglyNumber(int n)
{
    set<long long> s;

    s.insert(1);

    set<long long> t;

    while (s.size() < 2*n)
    {
        for (auto i = s.begin(); i != s.end(); i++)
        {
            long long x = *i;

            t.insert(2 * x);
            t.insert(3 * x);
            t.insert(5 * x);
        }

        s.insert(t.begin(), t.end());

        t.clear();
    }

    auto it = s.begin();

    for (int i = 0; i < n - 1; i++)
    {
        // cout<<"I am "<<i + 1<<" th uglu number : "<<*it<<endl;
        it++;
    }

    return *it;
}

int main()
{

    cout<<nthUglyNumber(10);

    return 0;
}
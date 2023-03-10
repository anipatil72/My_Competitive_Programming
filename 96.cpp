#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n, t = 0, f, g, h, d, k;

    cin >> n;

    vector<int> v;

    priority_queue<int> p;

    queue<pair<int,bool>> q;

    for (int i = 0; i < n; i++)
    {
        cin >> d;

        v.push_back(d);
        p.push(d);
    }

    cin >> k;
    //cout<<k<<endl;

    for (int i = 0; i < n; i++)
    {
        if (i == k)
        {
            q.push({v[i], true});
           
        }

        if (i != k)
        {
            q.push({v[i], false});
            
        }
    }

    while (!q.empty())
    {

        pair<int,bool> e = q.front();


        if (e.first == p.top())
        {
            if (e.second)
            {

                t++;
                break;
            }

            p.pop();
            q.pop();
            //cout<<f<<" "<<p.top().second<<",";
            t++;
            continue;
        }

        q.push(e);
        q.pop();
    }

   cout << t << endl;

    return 0;
}
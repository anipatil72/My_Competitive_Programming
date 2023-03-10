#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, s;
    vector<int> v;

    cin >> n >> s;

    for (int i = 0; i < n; i++)
    {
        int d;

        cin >> d;

        if (d == 1)
        {
            v.push_back(i);
        }
    }

    if (s>v.size())
    {
        cout<<"-1"<<endl;
        return ;
    }
    

    if (s==v.size())
    {
            cout<<"0"<<endl;
            return ;
    }
    

    int cfront = 0, cback = n - 1, a = 0;

    int vf = 0, vb = v.size() - 1;

    while (vf <= vb)
    {
        if (abs(vb - vf + 1) == s)
        {
            break;
        }

        if (abs(cfront - v[vf]) < abs(cback - v[vb]))
        {
            a = a + abs(cfront - v[vf]) + 1;

            cfront = v[vf] + 1;
            vf++;
            //cout<<"I am removing from the front and the value of a is "<<a<<endl;
            continue;
        }
        if (abs(cfront - v[vf]) >abs(cback - v[vb]))
        {
            a = a + abs(cback - v[vb]) + 1;

            cback = v[vb] - 1;
            // cout<<"the value of cback"<<cback<<" and v[vb]"<<v[vb]<<endl;
            // cout<<"I am removing from the back and the value of a is "<<a<<endl;
            vb--;
            continue;
        }

        if (abs(cfront - v[vf]) ==abs(cback - v[vb]))
        {
            a = a + abs(cback - v[vb]) + 1;

            cback = v[vb] - 1;
            // cout<<"the value of cback"<<cback<<" and v[vb]"<<v[vb]<<endl;
            // cout<<"I am removing from the back and the value of a is "<<a<<endl;
            vb--;
            continue;
        }
    }

    cout << a << endl;
}

int main()
{
    int t;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        solve();
    }

    return 0;
}
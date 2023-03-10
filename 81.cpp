#include <bits/stdc++.h>
using namespace std;

int main()
{

    // cout<<INT_MAX/1000000<<endl;
        time_t sart, end;
  
    /* You can call it like this : start = time(NULL);
     in both the way start contain total time in seconds 
     since the Epoch. */
        time(&sart);

        unordered_map<int, int> m;
        vector<int> v;

        int n, d, e = 0, f, start, last;
        cin>>n ;

        for (int i = 0; i < n; i++)
        {
            cin >> d;
            m[d]++;
            v.push_back(d);
        }

        for (int i = 0; i < n; i++)
        {
            d = v[i];
            int c = 0;

            d++;

            while (m.count(d) > 0)
            {
                //cout<<"I am here !"<<endl;
                d++;
                c++;
            }

            if (e < c)
            {
                e = c;
                start = v[i];
            }
        }

        cout << start << " " << start + e << endl;

        time(&end);
  
    // Calculating total time taken by the program.
    double time_taken = double(end - sart);
    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;

    return 0;
}
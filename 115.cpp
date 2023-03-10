#include <bits/stdc++.h>
using namespace std;

struct Interval
{
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

vector<Interval> insert(vector<Interval> &intervals, Interval newInterval)
{

    int n = intervals.size();
    int low, upper;
    int s = -1, e = -1;
    bool b1 = 1, b2 = 1;

    if (newInterval.end < intervals[0].start)
    {
        Interval to(newInterval.start, newInterval.end);

        intervals.insert(intervals.begin(), to);

        return intervals;
    }

    for (int i = 0; i < n; i++)
    {

        if (intervals[i].start >= newInterval.start)
        {
            low = newInterval.start;
            s = i;
            break;
        }
        if (intervals[i].end >= newInterval.start)
        {
            low = intervals[i].start;
            s = i;
            break;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (intervals[i].start == newInterval.end)
        {
            upper = intervals[i].end;
            e = i;
            break;
        }

        if (intervals[i].start > newInterval.end)
        {
            upper = newInterval.end;
            e = i - 1;
            break;
        }

        if (intervals[i].end >= newInterval.end)
        {
            upper = intervals[i].end;
            e = i;
            break;
        }
    }

    if (e == -1 || s == -1)
    {
        if (e == -1 && s == -1)
        {
            low = newInterval.start;
            upper = newInterval.end;

            Interval t(low, upper);

            intervals.push_back(t);
            return intervals;
        }

        if (e == -1 && s != -1)
        {
            upper = newInterval.end;

            e = n - 1;
        }
    }

    for (int i = s; i <= e; i++)
    {
        intervals.erase(intervals.begin() + i);
    }

    Interval ti(low, upper);

    intervals.insert(intervals.begin() + s, ti);

    return intervals;
}

int main()
{

    vector<Interval> v;

    Interval a(1, 3);
    Interval b(6, 9);

    v.push_back(a);
    v.push_back(b);

    Interval test(7, 10);

    vector<Interval> ans = insert(v, test);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i].start << " " << ans[i].end << endl;
    }

    // vector<int> v = {1,2,3,4,5};

    // v.insert(v.begin(),1 );

    // for (int i = 0; i < v.size(); i++)
    // {
    //         cout<<v[i]<<" ";
    // }

    return 0;
}
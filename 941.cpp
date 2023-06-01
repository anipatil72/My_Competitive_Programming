// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

class UndergroundSystem
{
    unordered_map<int, vector<string>> person;

    unordered_map<string, pair<double, int>> station;

public:
    UndergroundSystem()
    {
        person.clear();

        station.clear();
    }

    void checkIn(int id, string stationName, int t)
    {
        person[id].push_back(stationName);

        person[id].push_back(to_string(t));
    }

    void checkOut(int id, string stationName, int t)
    {
        string tem = person[id][0];

        string test = "";

        test = tem + '#' + stationName;

        // test = stationName + '#' + tem;

        int time = t - stoi(person[id][1]);

        station[test].first += time;

        station[test].second++;

        person[id].clear();
    }

    double getAverageTime(string startStation, string endStation)
    {
        string test = "";

        test = startStation + '#' + endStation;

        // test = endStation + '#' + startStation;

        auto x = station[test];

        double ans = 1.0 * x.first / x.second;

        return ans;
    }
};

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
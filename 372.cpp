#include <bits/stdc++.h>
using namespace std;

class MyCalendar
{
    set<pair<int, int>> s;

public:
    MyCalendar()
    {
    }

    

    bool book(int start, int end)
    {

        auto p = s.upper_bound({start, end});

        if (p == s.end())
        {

            if (s.empty())
            {
                s.insert({start, end});
                return true;
                    
            }
            else
            {
                auto x = s.end();
                auto y = --x;

                if (y->second<=start)
                {
                    s.insert({start, end});
                    return true;
                        
                }
                
            }
            
            
        }

        if (p->first >= end)
        {

            if (p != s.begin())
            {
                auto t = --p;

                if (t->second <= start)
                {
                    s.insert({start, end});
                    return true;
                }
            }
            else if (p == s.begin())
            {

                s.insert({start, end});
                return true;
            }
        }

        return false;
    }

    
};

int main()
{
    set<pair<int, int>> s;

    s.insert({2, 6});
    s.insert({4, 9});
    s.insert({10, 14});

    auto p = s.upper_bound({10, 11});

    if (p != s.end())
    {
        cout << p->first << " " << p->second << endl;
    }
    else
    {
        cout << "Big enough !" << endl;
    }
    // auto t = p;

    // cout << t->first << " " << t->second;

    return 0;
}
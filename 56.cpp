#include <iostream>
#include <list>
using namespace std;

int main()
{

    list<int> a;
    list<int>::iterator j, k;

    int t;

    cin >> t;
    while (t != -1)
    {
        a.push_back(t);
        cin >> t;
    }

    int n = a.size();

    j = a.begin();

    for (int i = 1; i < n + 1; i++)
    {

        // cout<<" I am here !"<<endl;
        if (i % 2 == 0)
        {
            a.erase(j);
        }

        j++;
    }

    k = a.begin();

    while (k != a.end())
    {
        cout << *k << " ";
        k++;
    }

    return 0;
}
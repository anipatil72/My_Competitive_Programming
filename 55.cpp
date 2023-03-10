#include <iostream>
#include <list>
using namespace std;

int main()
{

    list<int> a;

    int t;

    cin >> t;
    while (t != -1)
    {
        a.push_back(t);
        cin >> t;
    }

    list<int>::iterator i, j, k;

    a.reverse();

    i = a.begin();

    if (*i < 9)
    {
        *i = *i + 1;
    }

    if (*i == 9)
    {

        *i = 0;
        j = ++i;

        while (j != a.end() && (*j == 9))
        {
            *j = 0;

            j++;
        }
        *j = *j + 1;
        if (j == a.end())
        {
            a.push_back(1);
        }
    }

    a.reverse();

    k = a.begin();

    while (k != a.end())
    {
        cout << *k << " ";
        k++;
    }

    return 0;
}
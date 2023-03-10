#include <iostream>
#include <vector>
#include <list >
using namespace std;

template <class T>

void display(list <T> &v)
{

    for (auto i = v.begin(); i!= v.end(); i++)
    {
        cout <<*i << " ";
    }
}

int main()
{
    int n;

    cin >> n;

    scanf("\n");

    list <char> a;
    char d;

    for (int i = 0; i < n; i++)
    {
        cin >> d;

        a.push_back(d);
    }
    
    // a.pop_back();
    a.reverse();

    display(a);

   
    return 0;
}
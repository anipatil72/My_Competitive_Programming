#include <iostream>
#include <vector>
#include <list>

using namespace std;

template <class T>

void display(list<T> &v)
{

    class list<T>::iterator it;
    it = v.begin();

    for (it = v.begin(); it != v.end(); it++)
    {

        cout << *it << " ";
    }

    cout<<endl;
}

int main()
{

    list<int> v1;
    list<int> v2;
    int element;

    for (int i = 0; i < 4; i++)
    {
        cout << "Enter the element you want to insert in list 1  : ";
        cin >> element;
        v2.push_back(element);
    }

    // for (int i = 0; i < 4; i++)
    // {
    //     cout << "Enter the element you want to insert in list 2  : ";
    //     cin >> element;
    //     v1.push_back(element);
    // }

    // vector <int> :: iterator iter = v1.begin();
    //     v1.insert(iter,2,4);
    //         v1.pop_back();

    // for (int i = 0; i < v1.size(); i++)
    // {

    //     cout<<v1[i]<<endl;

    // }

    // v2.pop_front();

    v2.merge(v1);
    v2.sort();
    display(v2);
    v2.pop_back();
    v2.pop_back();
    v2.pop_back();
    v2.pop_back();

    cout<<v2.empty()<<endl;;
    // cout<<"\nlist 1 after reversing: ";

    // v2.reverse();
    // display(v2);


    return 0;
}
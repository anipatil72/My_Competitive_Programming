#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int mod(int cards)
{
    if (cards >= 0)
    {
        return cards;
    }

    return (-1) * cards;
}

bool isSorted(vector<int> &a, vector<int>::iterator beg, vector<int>::iterator end)
{
    if (beg == end)
    {
        return true;
    }

    if (*beg > *(beg + 1))
    {
        return false;
    }

    bool isSmallerSorted = isSorted(a, beg + 1, end - 1);

    return isSmallerSorted;
}

int lenSub(vector<int> &a)
{
    vector<int>::iterator i, j, k;
    int m = 0, h = 1;

    for (i = a.begin(); i < a.end(); i++)
    {

        for (j = i; j < a.end(); j++)
        {
            if (h)
            {
                m = mod(distance(i, j));
                h = 0;
            }

            int d = mod(distance(i, j));

            if (isSorted(a, i, j) && (d > m))
            {
               //cout<<"I am here ! "<<endl;
                m = d;
            }
        }

    }
        return m +1  ;
}

int main()
{

    vector <int> a1 = { 1,7,0 ,50 ,2,3,81,9, 150};

    // sort(a1.begin(),a1.end()-1);

    // for (int i = 0; i < a1.size(); i++)
    // {
    //     cout<<a1[i]<<" ";
            
    // }
    


    

    vector <int> :: iterator i,j ;

    cout<<lenSub(a1)<<endl ;

    return 0;
}
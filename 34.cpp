#include <iostream>
#include <vector>
using namespace std;


int minf(vector<int> &cards)
{

    int d, h, l, m,c;

    vector<int>::iterator i, j, k;

    for (m = 1; m < cards.size() +1; m++)
    {
        i = cards.begin();
        j = i + m;

        while (j != cards.end())
        {
            if (*i == *j)
            {
                //cout<<" I am here\n";
               // d = mod(distance(i, j));
                return m + 1;
            }

            i++;
            j++;
        }
    }

    return -1;
}

int main()
{

    vector <int> v = {1, 80, 18, 7 ,25 ,1,12,90,10};

    int ans = minf(v);

    cout<<ans<<endl;

    return 0;
}